/*This program implements a stack using a singly linked list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct stack mystack;
typedef struct node mynode;
struct stack
{
	int count;
	mynode *first;
	mynode *top;
	mynode *next;

};

struct node
{
	int value;
	struct node *next;
};

mystack new_stack()
{
	mystack temp;
	temp.top = NULL;
	temp.next = NULL;
	temp.first = NULL;
	temp.count = 0;
	return temp;
}

mynode* createnode(int value)
{
	mynode *temp = (mynode*)malloc(sizeof(mynode));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void push(mystack *ptr,int value)
{
	mynode *temp = createnode(value);
	(ptr->count)++;
	if (ptr->top == NULL)
	{
		ptr->next = ptr->top = temp;
		ptr->first = temp;
	}
	else
	{
		ptr->top->next = temp;
	}
	ptr->top = temp;
}

int pop(mystack *ptr)
{
	if (ptr->count==0)
	{
		printf("\nSorry,The stack is empty");
		return 0;
	}
	else if (ptr->count == 1)
	{
		ptr->first = ptr->next = ptr->top = NULL;
		ptr->count = 0;
	}
	else
	{
		(ptr->count)--;
		mynode *run = ptr->first;
		mynode *prev = NULL;
		while (run->next != NULL)
		{
			prev = run;
			run = run->next;
		}

		prev->next = NULL;
		ptr->top = prev;
		int value= run->value;
		free (run);
		return value;
	}
}

void printstack(mystack *ptr)
{
	mynode *run = ptr->first;
	while (run != NULL)
	{
		printf("\n%d", run->value);
		run = run->next;
	}
}

int main()
{
	mystack ptr = new_stack();

	for (int i = 0;i < 20;i++)
	{
		push(&ptr, i);
	}

	for (int i = 0;i < 23;i++)
	{
		pop(&ptr);
	}

	printf("\nPrinting Stack \n\n");
	printstack(&ptr);
	return 0;
}
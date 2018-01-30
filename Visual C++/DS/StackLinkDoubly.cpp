/*This program implements a stack data structure using doubly linked list*/
#include<stdio.h>
#include<stdlib.h>

typedef struct stack mystack;
typedef struct node mynode;

struct stack
{
	mynode *top;
	mynode *first;
	int count;
};

struct node
{
	int value;
	mynode *next;
	mynode *prev;
};

mystack new_stack()
{
	mystack temp;
	temp.first = temp.top = NULL;
	temp.count = 0;
	return temp;
}

mynode* createnode(int value)
{
	mynode *temp = (mynode*)malloc(sizeof(mynode));
	temp->value = value;
	temp->next = temp->prev=NULL;
	return temp;
}

void push(mystack *ptr, int value)
{
	mynode *temp = createnode(value);
	if (ptr->count == 0)
	{
		temp->prev = NULL;
		ptr->first = ptr->top =temp;
	}
	else
	{
		ptr->top->next = temp;
		temp->prev = ptr->top;
		ptr->top = temp;
	}
	ptr->count++;
}

int pop(mystack *ptr)
{
	int value;
	if (ptr->count == 0)
	{
		printf("\nSorry,The stack is empty");
		return 0;
	}
	else if (ptr->count == 1)
	{
		ptr->count--;
		value = ptr->top->value;
		free(ptr->top);
		ptr->top = ptr->first = NULL;
		return value;
	}
	else
	{
		ptr->count--;
		value = ptr->top->value;
		ptr->top = ptr->top->prev;
		ptr->top->next = NULL;
		return value;		
	}
}

void printstack(mystack *ptr)
{
	mynode *run = ptr->top;
	while (run != NULL)
	{
		printf("\n%d", run->value);
		run = run->prev;
	}
}


int main()
{
	printf("size of mystack : %d", sizeof(mystack));
	printf("\n\nsize of mynode : %d", sizeof(mynode));
	mystack var1 = new_stack();
	mystack var2 = new_stack();
	for (int i = 0;i < 40;i++)
	{
		if (i <= 20)
		{
			push(&var1, i);
		}
		else
		{
			push(&var2, i);
		}
	}

	printf("\nPrinting stack1\n\n");
	printstack(&var1);
	printf("\n\nPrinting stack2\n\n");
	printstack(&var2);
	for (int i = 0;i < 20;i++)
	{
		if (i < 10)
		{
			pop(&var1);
		}
		else
		{
			pop(&var2);
		}
	}

	printf("\n\nPrinting stack1\n\n");
	printstack(&var1);
	printf("\n\nPrinting stack2\n\n");
	printstack(&var2);
	return 0;
}
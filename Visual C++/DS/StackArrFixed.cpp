/*This is a c program which implements a stack data structure using an array of size 100 */

#include<stdio.h>
#include<stdlib.h>

struct stack {
	int arr[100];
	int top;
};

typedef struct stack mystack;

int isfull(mystack *ptr)
{
	if ((ptr->top) == 99)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}

int isempty(mystack *ptr)
{
	if ((ptr->top) == (-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void push(mystack *ptr, int value)
{
	if (!(isfull(ptr)))
	{
		ptr->arr[++(ptr->top)] = value;
	}
	else
	{
		printf("\nStack is full");
	}
}

int pop(mystack *ptr)
{
	if (!isempty(ptr))
	{
		return ptr->arr[ptr->top];
		ptr->top--;
	}
	else
	{
		printf("\nStack is empty");
	}
}

void printstack(mystack *ptr)
{
	int i = ptr->top;
	while (i > -1)
	{
		printf("\n%d", ptr->arr[i--]);
	}
}

int main()
{
	mystack a;
	a.top = -1;
	
	for (int i = 0;i < 10;i++)
	{
		push(&a,i);
	}

	printstack(&a);
	return 0;
}
/*
 * This program implements a stack in c
 *
 *  Created on: 07-Jul-2016
 *      Author: Balraj
 *
 */
#include<stdio.h>

struct stack
{
	int top;
	int arr[100];
};

typedef struct stack mystack;

int isempty(mystack *ptr)
{
	if(ptr->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull(mystack *ptr)
{
	if(ptr->top==99)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(mystack *ptr,int value)
{
	if(!isfull(ptr))
	{
		ptr->arr[++(ptr->top)]=value;
	}
	else
	{
		printf("\nSorry, The stack is full");
	}
}

int pop(mystack *ptr)
{
	if(!isempty(ptr))
	{
		return ptr->arr[(ptr->top)--];
	}
	else
	{
		printf("Sorry,The stack is empty");
		return 0;
	}

}

void printstack(mystack *ptr)
{
	int i=ptr->top;
	while(i>-1)
	{
		printf("\n%d",ptr->arr[i--]);
	}
}

int main()
{
	mystack a;
	a.top=-1;

	for(int i=0;i<10;i++)
	{
		push(&a,i);
	}

	printstack(&a);
	return 0;
}

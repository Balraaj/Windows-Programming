//This program implements stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct inode* listptr;
listptr top;
typedef struct inode
{
	int data;
	listptr next;
};

void push(int c)
{
	listptr temp;
	temp = (inode *)malloc(sizeof(inode));
	temp->data = c;
	temp->next = top;
	top = temp;
}

int pop()
{
	char c;
	listptr temp;
	if (top != NULL)
	{
		temp = top;
		top = top->next;
		c = temp->data;
		free(temp);
		return c;
	}
}

void main()
{
	printf("values pushed :");
	for (int i = 0; i < 10; i++)
	{
		push(i*2);
		printf(" %d", i*2);
	}
	
	printf("\n\nValues poped  :");
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", pop());
	}
}
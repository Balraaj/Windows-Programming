/*This program implements a Stack datastructure with an array and size of array is specified by the user
it is not fixed, a constructor like function is called , to which size is passed. in this program the 
new_stack function returns a mystack and not a pointer to mystack*/

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
};

typedef struct stack mystack;

mystack new_stack(int size)
{
	mystack temp;
	temp.size = size;
	temp.top = -1;
	temp.arr = (int *)malloc(size*(sizeof(int)));
	return temp;
	/*In this case temp is local varibale but we are returning it to calling function. how it works ? 
	  Because in this case a copy of temp is created and that copy is assigned to the calling function.
	  dynamically allocated arr creates no problems because its content (address of first location in 
	  dynamically allocated chunck) is also copied*/
}

int isfull(mystack *ptr)
{
	if ((ptr->top) == (ptr->size - 1))
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
	if (ptr->top == -1)
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
	if (!isfull(ptr))
	{
		ptr->arr[++(ptr->top)] = value;
	}
	else
	{
		printf("\nSorry,The stack is full");
	}
}

int pop(mystack *ptr)
{
	if (!isempty(ptr))
	{
		return ptr->arr[(ptr->top)--];
	}
	else
	{
		printf("\nSorry,The stack is empty");
		return 0;
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
	mystack ptr = new_stack(100);

	for (int i = 0;i < 20;i++)
	{
		push(&ptr, i);
	}
	printf("\nPrinting stack");
	printstack(&ptr);
	for (int i = 0;i < 22;i++)
	{
		pop(&ptr);
	}
	printf("\nPrinting stack");

	return 0;
}
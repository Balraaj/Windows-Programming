#include<stdio.h>
#define size 100
char stack[size];
int top;
void push(char *);
void pop();
void main()
{
	char arr[size];
	char c;
	int i = 0;
	printf("Enter your string (max size 100) : ");
	
	while (1)
	{
		char c = getchar();
		if (c == '\n')
			break;
		arr[i++] = c;
	}
	arr[i++] = '\0';

	push(arr);

	printf("\nReversed string : ");
	pop();
	
	}


void push(char *x)
{
	
	int i = 0;
	while ((top < size) && (x[i] != '\0'))

	{

		stack[top++] = x[i++];
	}
	if ((top < size) && (x[i] == '\0'))
		stack[top++] = '\0';
	
}

void pop()
{
	top--;
	int i = 0;
	char arr[size];
	while(top>0)
	{
		arr[i++] = stack[--top];
	}
	arr[i] = '\0';
	printf("%s", arr);
}


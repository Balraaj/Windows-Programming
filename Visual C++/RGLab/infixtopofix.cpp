//This program converts infix to prefix
#include<stdio.h>
#include<string.h>
#define size 50
char stack[size];
int top;

void push(char c)
{
	stack[top++] = c;
}

char pop()
{
	return stack[--top];
}

char TOP()
{
	return stack[top - 1];
}

int IEP(char c)
{
	switch (c)
	{
	case ')':
		return 4;
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	default:
		return 0;

	}
}

int ISP(char c)
{
	switch (c)
	{
	case ')':
		return 1;
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	default:
		return 0;
	}
}

void infixtoprefix(char infix[], char prefix[])
{
	int i, j;
	i = j = 0;
	strrev(infix);
	push('#');
	while (infix[i] != '\0')
	{
		switch (infix[i])
		{
		case ')':
		case '*':
		case '/':
		case '+':
		case '-':
			while (ISP(TOP()) >= IEP(infix[i]))
			{
				prefix[j++] = pop();
			}
			push(infix[i]);
			break;

		case '(':
			while (TOP() != ')')
			{
				prefix[j++] = pop();
			}
			pop();
			break;

		default:
			prefix[j++] = infix[i];
		}
		i++;
	}
	while (top>1)
	{
		prefix[j++] = pop();
	}
	prefix[j] = '\0';
	strrev(prefix);
}

void main()
{
	char a[50], b[50];
	printf("Enter infix = ");
	scanf("%s", a);
	infixtoprefix(a, b);
	printf("\nprefix = %s", b);
}
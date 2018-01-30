#include<stdio.h>
char out[50];
int n = 0;
char stack[50];
int top = -1;

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	return stack[top--];
}

char TOP()
{
	return stack[top];
}

int priority(char x)
{
	if (x == '#')
		return 0;
	else if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
}

int compare(int x, int y)
{
	if (x > y)
		return 1;
	else
		return 0;
}

int oprate(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 1;
	else
		return 0;
}

void postfix(char *x)
{
	int i = 0;
	int c;
	while (x[i] != '\0')
	{
		c = oprate(x[i]);
		
		if (c == 1)
		{
			int value = compare(priority(x[i]), priority(TOP()));

			if (value == 0)
			{
				while (priority(x[i]) <= priority(TOP()))
				{
					out[n++] = pop();
				}
			}
			push(x[i]);
		}
		else
		{
			out[n++] = x[i];
		}
		i++;
	}
	while (stack[top] != '#')
	{
		out[n++] = pop();
	}
}
void main()
{
	push('#');
	char arr[50];
	printf("Enter your expression = ");
	scanf("%s",arr);

	postfix(arr);
	printf("\n\nPostfix = %s", out);
	printf("\n\n");
	
}
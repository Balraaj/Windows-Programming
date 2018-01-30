// This program shows use of function pointers 



#include<stdio.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

typedef int(*fptr1)(int, int);

fptr1 choose(char x)
{
	switch (x)
	{
	case '+':
		return add;
	case '-':
		return sub;
	}
}

int execute(char x, int m, int n)
{
	fptr1 operation = choose(x);
	return operation(m, n);
}

void main()
{
	char a;
	int b, c;
	printf("What operation you want to perform = ");
	scanf("%c",&a);
	printf("\nEnter value = ");
	scanf("%d",&b);
	printf("\nEnter value = ");
	scanf("%d",&c);

	printf("Result is = %d", execute(a, b, c));
	}
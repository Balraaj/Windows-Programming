#include<stdio.h>
#include<conio.h>
int sum = 0;
static int i = 0;
int cal(int);
int f(int);
void main()
{
	int z = 2 * f(3);
	printf("value = %d", z);
}

int f(int x)
{
	int z = x - i;
	while (z != i)
	{
		sum = sum + cal(x - i)*cal(i);

			i++;
		z = x - i;
	}
	return sum;
}

int cal(int x)
{
	if (x == 0)
		return 1;
	else
		return cal(x)+cal(x - 1);
}
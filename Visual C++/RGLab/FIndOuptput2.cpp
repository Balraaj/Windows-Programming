#include<stdio.h>
#include<conio.h>
int main(void)
{
	int i = 10, j = 10, k = 10,l;
	l = ++i || j++&&k++;
	printf("\n%d\t%d\t%d\t%d", i, j, k, l);
	int a = 5, b = 7, c = 10, d;
	d = ++a && ++b || c++;
	printf("\n%d\t%d\t%d\t%d", a, b, c, d);
	return 0;
}
#include<stdio.h>
#include<conio.h>
int strnlen(char *);
void strswap(char *, char *);
int main(void)
{
	char arr[100];
	char str[100];
	printf("Enter your first string = ");
	scanf("%[^EXIT]s", arr);
	fflush(stdin);
	printf("Enter your second string = ");
	scanf("%[^EXIT]s", str);

	strswap(arr, str);
	printf("\nContents of arr = %s", arr);
	printf("\nContents of str = %s", str);
	return 0;
}

void strswap(char *x, char *y)
{
	int m = strnlen(x);
	int n = strnlen(y);
	int control;
	if (m > n)
		control = m;
	else
		control = n;
	char temp[100];
	int i = 0;
	while (i<control)
	{
		temp[i] = x[i];
		x[i] = y[i];
		y[i] = temp[i];
		i++;
	}
	y[i] = x[i] = '\0';
	
}

int strnlen(char *x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		i++;
	}
	return i;
}
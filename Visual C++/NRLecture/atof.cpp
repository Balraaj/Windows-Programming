#include<stdio.h>
#include<conio.h>
float stringtofloat(char *);
float power(int);
int main(void)
{
	char arr[20];
	printf("Enter string = ");
	scanf("%s", arr);
	float z = stringtofloat(arr);
	printf("\n\nFloat value = %f", z);
	getch();
	return 0;
}

float power(int x)
{
	int product = 1, raise = x;
	for (int i = 0; i < raise; i++)
	{
		product *= 10;
	}
	return product;
}

float stringtofloat(char *x)
{
	char *y = x;
	float value = 0;
	while (*y != '.')
	{
		value = value * 10 + (*y) - '0';
		y++;

	}

	y++;
	int j = 1;
	while (*y != '\0')
	{
		float devide = power(j++);
		value = value + (1 / devide)*(*y-'0');
		y++;
	}
	return value;

}
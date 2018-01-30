//This program takes integer input and converts it to string
#include<stdio.h>
#include<conio.h>
void inttostring(int);
int main(void)
{
	int a;
	printf("Enter integer value = ");
	scanf("%d", &a);
	inttostring(a);
	getch();
	return 0;
}

void inttostring(int x)
{
	int temp, count = 0;
	temp = x;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

	char arr[20];
	arr[count--] = '\0';
	while (count >= 0)
	{
		arr[count] = x % 10 + '0';
		count--;
		x /= 10;
	}
	

	printf("\nString value = %s", arr);
}
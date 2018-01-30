//This program multiplies two matrices and uses a function to do that
#include<stdio.h>

void mul(int a[][3], int b[][3], int c[][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			int sum = 0;
			for (int k = 0;k < 3;k++)
			{
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
}

void input(int arr[][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("\nEnter value = ");
			scanf("%d", &arr[i][j]);
		}
	}
}
void print(int arr[][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("  %d", arr[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int a[3][3];
	int b[3][3];
	int c[3][3];
	printf("Enter elements of first matrix : \n	");
	input(a);
	printf("\n\nEnter elements of second matrix : \n");
	input(b);
	mul(a, b, c);
	printf("\n\nResult is : \n\n");
	print(c);

}
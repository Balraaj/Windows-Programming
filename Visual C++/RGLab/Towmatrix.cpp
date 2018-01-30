#include<stdio.h>
#include<conio.h>

int main(void)
{
	int x[2][2], y[2][2], z[2][2], i, j;


	printf("Enter elements of first matrix:");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("\nEnter value = ");
			scanf("%d", &x[i][j]);
		}

	}

	printf("\nEnter elements of second matrix: \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("\nEnter value = ");
			scanf("%d", &y[i][j]);
		}
	}



	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)

		{
			int sum = 0;
			for (int k = 0; k < 2; k++)
			{
				sum = sum + x[i][k] * y[k][j];
			}
			z[i][j] = sum;
		}
	}

	printf("\n\nMultiplication of two matrices:\n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("\t%d", z[i][j]);
		}
		printf("\n");
	}
	return 0;
}
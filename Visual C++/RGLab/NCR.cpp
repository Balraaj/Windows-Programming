#include<stdio.h>
#include<conio.h>
int main(void)
{
	int i, j, n, r, c[150][150];
	printf("Enter the value of N = ");
	scanf("%d", &n);
	printf("\nEnter the value of R = ");
	scanf("%d", &r);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				c[i][j] = 1;
			else
			{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}

	printf("\nValue of nCr = %d", c[n][r]);
	getch();
}
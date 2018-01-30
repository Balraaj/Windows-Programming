#include<stdio.h>
#include<conio.h>

int main(void)
{
	int x[2][2], y[2][2], z[2][2], i, j;
	int m1, m2, m3, m4, m5, m6, m7;

	printf("Enter elements of first matrix:");
	
	for (i = 0; i < 2; i++)
    {
		for (j = 0; j < 2; j++)
		{
            scanf("%d", &x[i][j]);
		}
		
	}

	printf("\nEnter elements of second matrix: \n");
	
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &y[i][j]);
		}
	}

	m1 = (x[0][0] + x[1][1])*(y[0][0] + y[1][1]);
	m2 = (x[1][0] + x[1][1])*y[0][0];
	m3 = x[0][0] * (y[0][1] - y[1][1]);
	m4 = x[1][1] * (y[1][0] - y[0][0]);
	m5 = (x[0][0] + x[0][1])*y[1][1];
	m6 = (x[1][0] - x[0][0])*(y[0][0] + y[0][1]);
	m7 = (x[0][1] - x[1][1])*(y[1][0] + y[1][1]);

	z[0][0] = m1 + m4 - m5 + m7;
	z[0][1] = m3 + m5;
	z[1][0] = m2 + m4;
	z[1][1] = m1 - m2 + m3 + m6;

	printf("After multiplication using \n");
	for (i = 0; i<2; i++)
	{
		
			printf("\n");

			for (j = 0; j < 2; j++)
			{
				printf("%d\t", z[i][j]);
			}
		
	}

	return 0;
}
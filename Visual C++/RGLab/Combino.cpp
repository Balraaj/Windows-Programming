#include<stdio.h>
#include<conio.h>
int main(void)
{
	int src[5], temp[30], i, j, m = 5, n;
	for (i = 0; i < 5; i++)
	{
		printf("\nEnter %d value = ", (i + 1));
		scanf("%d", &src[i]);

	}

	for (i = 0; i < 5; i++)
	{
		temp[i] = src[i];
	}

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			temp[m] = src[i] * 10 + src[j];
			m++;
		}
	}

	printf("\nEnter position \n");
	scanf("%d", &n);
	printf("\nNumber is = %d", temp[n - 1]);

	return 0;
}
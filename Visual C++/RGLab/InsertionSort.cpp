#include<stdio.h>
int* sort(int *x)
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = i + 1;j < 10;j++)
		{
			if (x[i] > x[j])
			{
				int temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	return x;
}

void main()
{
	int arr[10];
	printf("Enter list to sort : ");
	for (int i = 0;i < 10;i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nYou entered : ");
	for (int i = 0;i < 10;i++)
	{
		printf(" %d", arr[i]);
	}

	int *p = sort(arr);
	printf("\n\nsorted list : ");
	for (int i = 0;i < 10;i++)
	{
		printf(" %d", p[i]);
	}

	getchar();
}
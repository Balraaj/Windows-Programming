//This program shows working of Bubble sort
#include<stdio.h>
int* sort(int *x)
{
	int j = 0;
	int flag = 1;
	while(flag)
	{
		j++;
		flag = 0;
		for (int i = 0;i < 10-j;i++)
		{
			
			if (x[i] > x[i + 1])
			{
				flag = 1;
				int temp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = temp;
			}

		}
	}
	return x;
}

void main()
{
	int arr[10];
	printf("Enter list to be sorted : ");
	for (int i = 0;i < 10;i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nYou entered : ");
	for (int i = 0;i < 10;i++)
	{
		printf(" %d", arr[i]);
	}

	int *p =sort(arr);
	printf("\nSorted list : ");
	for (int i = 0;i < 10;i++)
	{
		printf(" %d", p[i]);
	}

	getchar();
}
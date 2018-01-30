//This program shows how to pass a 2D array to function
#include<stdio.h>

void print(int arr[][3])
{
	for (int i = 0;i < 2;i++)
	{
		for (int k = 0;k < 3;k++)
		{
			printf("  %d", arr[i][k]);
		}
		printf("\n");
	}
}

void input(int arr[][3])
{
	for (int i = 0;i < 2;i++)
	{
		for (int k = 0;k < 3;k++)
		{
			printf("\nEnter value = ");
			scanf("%d", &arr[i][k]);
		}
	}
}
void main()
{
	int list[2][3];
	input(list);
	print(list);

	
}
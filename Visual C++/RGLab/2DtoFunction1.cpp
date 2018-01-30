//Accessing a 2D array using a pointer to int
#include<stdio.h>
void input(int *p)
{
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				printf("\nEnter value = ");
				scanf("%d", (p + (i *2* 2 + j*2+k)));
			}
		}
	}
}

void print(int *p)
{
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				printf(" %d", *(p + (i * 2 * 2 + j * 2 + k)));
			}
		}
		printf("\n");
	}
}

void main()
{
	int arr[2][2][2];
	input(&arr[0][0][0]);
	print(&arr[0][0][0]);

}
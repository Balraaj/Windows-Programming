#include<stdio.h>
#include<stdlib.h>

void mySort(int *arr);

void main()
{
	int *arr = (int*)malloc(10*(sizeof(int)));
	
	for(int i=0,j=10;i<10;i++)
	{
		arr[i] = j--;	
	}
	
	printf("original array is :");
	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}	
	mySort(arr);
	printf("\n\nSorted array is : ");
	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}	
}

void mySort(int arr[])
{
	for(int i=0;i<9;i++)
	{
		int minIndex = i;

		for(int j=i+1;j<10;j++)
		{
			if(arr[j]<arr[minIndex])
			{
				minIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}

}


#include<stdio.h>
#include<stdlib.h>

void mySort(int *arr);

void main()
{
	int *arr = (int*)malloc(10*sizeof(int));
	printf("Original array is : ");

	for(int i=0,j=1000;i<10;i++)
	{
		arr[i]=j--;
		printf(" %d",arr[i]);
	}

	mySort(arr);

	printf("\nSorted array is : ");

	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}

}

void mySort(int arr[])
{
	for(int i=1;i<10;i++)
	{
		int value = arr[i];
		int j = i-1;

		while((j>=0)&&(arr[j]>value))
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = value;
	}
}

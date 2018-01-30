//This is an implementation of mergesort in C
#include<stdio.h>
#include<stdlib.h>

void Merge(int *arr1,int n, int* arr2,int m,int *arr)
{
	int i, j, k;
	i = j = k = 0;

	while ((i < n) && (j < m))
	{
		if (arr1[i] < arr2[j])
		{
			arr[k++] = arr1[i++];

		}
		else
		{
			arr[k++] = arr2[j++];
		}
	}

	while (i < n)
	{
		arr[k++] = arr1[i++];
	}

	while (j < m)
	{
		arr[k++] = arr2[j++];
	}
}

void MergeSort(int *arr,int size)
{
	if (size == 1)
	{
		return;
	}

	int n = size / 2;
	int m = size- n;
	int i = 0;

	int *arr1 = (int*)malloc(n*(sizeof(int)));
	int *arr2 = (int*)malloc(m*(sizeof(int)));

	for (;i < n;i++)
	{
		arr1[i] = arr[i];
	}

	int j = 0;

	for (;j < m;j++,i++)
	{
		arr2[j] = arr[i];
	}

	MergeSort(arr1, n);
	MergeSort(arr2, m);
	Merge(arr1,n, arr2,m, arr);
}



void main()
{
	int arr[10] = { 98,12,345,1,678,342,11,98,5467,45 };
	MergeSort(arr, 10);

	printf("Sorted array is : ");
	for (int i = 0;i < 10;i++)
	{
		printf("  %d", arr[i]);
	}


}







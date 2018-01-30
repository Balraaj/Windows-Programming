//This program implements QuickSort in C
#include<stdio.h>

int Part(int *arr, int end)
{
	int pindex = 0;
	int pivot = arr[end];

	for (int i = 0;i < end;i++)
	{
		if (arr[i] < pivot)
		{
			int temp = arr[pindex];
			arr[pindex] = arr[i];
			arr[i] = temp;
			pindex++;
		}
	}

	arr[end] = arr[pindex];
	arr[pindex] = pivot;

	return pindex;
}

void QuickSort(int *arr, int start,int end)
{
	if (start<end)
	{
		int pindex = Part(arr, end);
		QuickSort(arr, start, pindex - 1);
		QuickSort(arr, pindex + 1, end);
	}
}


void main()
{
	int arr[10] = { 123,345,1,23,678,6765,54,43,76,29 };
	QuickSort(arr, 0, 9);

	printf("Sorted array is : ");

	for (int i = 0;i < 10;i++)
	{
		printf(" %d", arr[i]);
	}
}
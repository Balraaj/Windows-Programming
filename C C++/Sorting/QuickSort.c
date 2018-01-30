#include<stdio.h>
#include<stdlib.h>

int part(int arr[],int start,int end)
{
	int pivotValue = arr[end];
	int pivotIndex = start;

	for(int i=start;i<end;i++)
	{
		if(arr[i]<pivotValue)
		{
			int temp = arr[i];
			arr[i] = arr[pivotIndex];
			arr[pivotIndex] = temp;
			pivotIndex++;	
		}
	}
	
	arr[end]=arr[pivotIndex];
	arr[pivotIndex]=pivotValue;
	return pivotIndex;
}

void mySort(int arr[],int start,int end)
{
	if(start<end)
	{
		int pivotIndex = part(arr,start,end);
		mySort(arr,start,pivotIndex-1);
		mySort(arr,pivotIndex+1,end);
	}
}

void main()
{
	int arr[10] = {123,9,-123,-2,0,0,1,2,2342,1};

	printf("Original array is : ");	
	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}
	
	mySort(arr,0,9);

	printf("\nSorted  array  is : ");

	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}
}

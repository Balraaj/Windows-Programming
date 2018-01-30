#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int index,int heapsize)
{
	int left = 2*index+1;
	int right = 2*index+2;
	int maximum = index;

	if((left<=heapsize)&&(arr[left]>arr[index]))
	{
		maximum = left;
	}

	if((right<=heapsize)&&(arr[right]>arr[maximum]))
	{
		maximum = right;
	}
	
	if(maximum!=index)
	{
		int temp = arr[maximum];
		arr[maximum] = arr[index];
		arr[index]=temp;
		heapify(arr,maximum,heapsize);
	}
}

void buildHeap(int arr[],int size)
{
	int start = (size-2)/2;
	
	for(int i=start;i>=0;i--)
	{
		heapify(arr,i,size-1);
	}
}

void mySort(int arr[],int size)
{
	buildHeap(arr,size);
	int heapsize = size-1;
	
	printf("\nHeap is : ");	
	for(int i=0;i<size;i++)
	{
		printf(" %d",arr[i]);
	}
	for(int i=size-1;i>=1;i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr,0,--heapsize);
	}
}

void main()
{
	int arr[]={123,2,2,21,-12,-3454,123,987,-444};

	printf("Original array is : ");
	for(int i=0;i<9;i++)
	{
		printf(" %d",arr[i]);
	}

	mySort(arr,9);

	printf("\nSorted array is : ");
	for(int i=0;i<9;i++)
	{
		printf(" %d",arr[i]);
	}
}






























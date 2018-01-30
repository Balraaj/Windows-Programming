#include<stdio.h>
#include<stdlib.h>

void merge(int arr1[],int arr2[],int arr[],int n,int m)
{
	int i,k,j;
	i=j=k=0;

	while((i<n)&&(j<m))
	{
		if(arr1[i]<arr2[j])
		{
			arr[k++]=arr1[i++];
		}
		else
		{
			arr[k++]=arr2[j++];
		}
	}

	while(i<n)
	{
		arr[k++]=arr1[i++];
	}

	while(j<m)
	{
		arr[k++]=arr2[j++];
	}
}

void mySort(int arr[],int size)
{
	if(size>1)
	{
		int n = size/2;
		int m = size-n;

		int *arr1 = (int*)malloc(n*sizeof(int));
		int *arr2 = (int*)malloc(m*sizeof(int));

		int k = 0;

		for(int i=0;i<n;i++)
		{
			arr1[i]=arr[k++];
		}

		for(int i=0;i<m;i++)
		{
			arr2[i]=arr[k++];
		}

		mySort(arr1,n);
		mySort(arr2,m);
		merge(arr1,arr2,arr,n,m);
	}
}

void main()
{
	int arr[]={123,2,2,1,1,-123,123,5111,-13123};

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

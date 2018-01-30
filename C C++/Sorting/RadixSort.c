#include<stdio.h>
#include<stdlib.h>
int* CountingSort(int arr[],int exp,int size);
int* rSort(int arr[],int size)
{
	int m=0;
	int exp=1;

	for(int i=0;i<size;i++)
	{
		if(arr[i]>m)
		{
			m=arr[i];
		}
	}

	while(m/exp>0)
	{
		arr=CountingSort(arr,exp,size);
		exp*=10;	
	}
	return arr;
}

int* CountingSort(int arr[],int exp,int size)
{
	int temp[10];
	for(int i=0;i<10;i++)
	{
		temp[i]=0;
	}

	for(int i=0;i<size;i++)
	{
		temp[(arr[i]/exp)%10]=temp[(arr[i]/exp)%10]+1;
	}

	for(int i=1;i<10;i++)
	{
		temp[i]=temp[i]+temp[i-1];
	}

	int *b = (int*)malloc(size*(sizeof(int)));

	for(int i=size-1;i>=0;i--)
	{
		b[temp[(arr[i]/exp)%10]-1]=arr[i];
		temp[(arr[i]/exp)%10]=temp[arr[i]/exp%10]-1;
	}

	return b;
}

void main()
{
	int* arr = (int*)malloc(7*(sizeof(int)));

	arr[0]=123;
	arr[1]=1;
	arr[2]=6;
	arr[3]=89;
	arr[4]=56;
	arr[5]=90;
	arr[6]=900;	
	arr=rSort(arr,7);

	printf("Sorted array is : ");

	for(int i=0;i<7;i++)
	{
		printf(" %d",arr[i]);
	}
}

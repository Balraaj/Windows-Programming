#include<stdio.h>
#include<stdlib.h>

void mySort(int arr[],int length,int k)
{	
	//Create an array of size equal to the largerst element in input
	//it will be used to count the number of occurunces of each 
	//number
	int c[k+1];
	
	for(int i=0;i<k+1;i++)
	{
		c[i]=0;
	}
	
	
	for(int i=0;i<length;i++)
	{
		c[arr[i]]=c[arr[i]]+1;
		//printf("\narr[%d] is : %d",i,);	
	
	}

	for(int i=1;i<k+1;i++)
	{
		c[i]=c[i]+c[i-1];
		//printf("\nC[%d] is : %d",i,c[i]);	
	}

	int a[length];

	for(int i=length-1;i>=0;i--)
	{
		a[c[arr[i]]-1]=arr[i];
		c[arr[i]]=c[arr[i]]-1;
	}

	for(int i=0;i<length;i++)
	{
		arr[i]=a[i];	
	}
}

void main()
{
	int arr[]={12,1,3,9,45,23,1,2,2,2};

	printf("Original array is : ");
	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}

	printf("\nSorted array is : ");
 	mySort(arr,10,45);

	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]);
	}
}

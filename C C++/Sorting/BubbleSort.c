#include<stdio.h>
#include<stdlib.h>

void mySort(int *arr);

void main()
{
	int *arr = (int*)malloc(10*(sizeof(int)));
	printf("Original array is : ");	
	for(int i=0,j=100;i<10;i++)
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
	for(int i=0;i<9;i++)
	{
		int flag = 0;

		for(int j=0;j<10-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;	
			}

			if(flag==0)
			{
				break;
			}
		}
	}
}


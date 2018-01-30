#include<iostream>
using namespace std;

int part(int *arr, int start, int end)
{
	int pivot = arr[end];
	int pindex = start;
	for (int i = start;i < end;i++)
	{
		if (arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pindex];
			pindex++;
		}
	}
	int temp = pivot;
	arr[end] = arr[pindex];
	arr[pindex] = pivot;
	return pindex;
}

void Q_sort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pindex = part(arr, start, end);
		Q_sort(arr, start, pindex - 1);
		Q_sort(arr, pindex + 1, end);
	}
}

void main()
{
	int arr[6]{ 132,234,543,652,128,908 };
	Q_sort(arr, 0, 5);
	for (int i = 0;i < 6;i++)
	{
		cout << "\n" << arr[i];
	}
}
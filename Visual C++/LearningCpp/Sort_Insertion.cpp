/* This program implements the insertion sort algorithm*/
#include<iostream>
using namespace std;

void sort(int size, int *p)
{
	for (int i = 1;i < size;i++)
	{
		for (int j = i;j >=1;j--)
		{
			int temp;
			if (p[j] < p[j-1])
			{
				temp = p[j-1];
				p[j-1] = p[j];
				p[j] = temp;
			}
		}
	}
}

void main()
{
	int arr[10];
	for (int i = 0;i < 10;i++)
	{
		cout << "\nEnter no : ";
		cin >> arr[i];
	}

	sort(10, arr);

	cout << "\n\nArray after sorting\n\n";
	for (int i = 0;i < 10;i++)
	{
		cout << "\n" << arr[i];
	}
}
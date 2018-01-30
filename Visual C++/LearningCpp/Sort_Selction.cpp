/* This program implements the selection sort*/

#include<iostream>
using namespace std;

void sort(int size, int *p)
{
	for (int i = 0;i < size -1;i++)
	{
		int value=p[i];
		for (int j = i+1;j < size ;j++)
		{
			if (value > p[j])
			{
				int temp = value;
				value = p[j];
				p[j] = temp;
			}
		}
		p[i]=value;
	}
}

void main()
{
	int arr[5];
	for (int i = 0;i < 5;i++)
	{
		cout << "Enter value : ";
		cin >> arr[i];
	}

	sort(5, arr);
	cout << "\nAfter sorting\n";
	for (int i = 0;i < 5;i++)
	{
		cout << "\n" << arr[i];
	}
}
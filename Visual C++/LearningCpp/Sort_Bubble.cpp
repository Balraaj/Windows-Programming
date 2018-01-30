/* This program implements the Bubble sort*/
#include<iostream>
using namespace std;

void sort(int size, int *p)
{
	for (int i = 0;i < size - 1;i++)
	{
		cout << "\nRound : " << i + 1;
		bool flag = false;  // to break if no swapping occurs
		for (int j = 0;j < size - i-1;j++)
		{
			int temp;
			if (p[j] > p[j + 1])
			{
				flag = true;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}

		}
		if (flag == false) //to break if no swapping occured
		{
			break;
		}
	}
}

void main()
{
	int arr[10];
	for (int i = 0;i < 10;i++)
	{
		cout << "Enter value : ";
		cin >> arr[i];
	}

	sort(10, arr);
	cout << "\n\nAfter sorting \n\n";
	for (int i = 0;i < 10;i++)
	{
		cout << "\n" << arr[i];
	}
}
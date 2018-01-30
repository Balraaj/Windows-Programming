/*This program shows how dynamic 2d array can be created*/

#include<iostream>
using namespace std;

void main()
{
	int *ptr[4]; // Create an array of 4 pointers

	for (int i = 0;i < 4;i++)
	{
		ptr[i] = new int[4];  // Assign an array of 4 integers to every pointer
	}

	int **arr;  // create a double pointer

	arr = &ptr[0]; // assign address of first array to double pointer

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			arr[i][j] = 1;
		}
	}

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
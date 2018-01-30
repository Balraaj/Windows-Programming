/*This program shows how pointer to 2d array can be used to access elements of 2D array*/
#include<iostream>
using namespace std;

void main()
{
	int arr[2][2] = { 1,2,3,4 };
	int(*ptr)[2][2];
	ptr = &arr;

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			cout <<"    "<< (*ptr)[i][j];
		}
		cout << endl;
	}
}
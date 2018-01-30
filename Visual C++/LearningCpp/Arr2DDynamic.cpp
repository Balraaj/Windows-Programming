/*This program created a dynamic 2-d array*/
#include<iostream>
using namespace std;

int main()
{
	int **ptr = new int*[2]; //creates an array of pointers and assings the address to ptr

	for (int i = 0;i < 2;i++)
	{
		ptr[i] = new int[2];
	}

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			ptr[i][j] = j;
		}
	}

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			cout << endl << ptr[i][j];
		}
	}


}
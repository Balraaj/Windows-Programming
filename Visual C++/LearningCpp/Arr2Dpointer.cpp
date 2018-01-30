/*This program shows how a 2-d array can be iterated using a pointer*/
#include<iostream>
using namespace std;

int main()
{
	int arr[2][2] = { 1,2,3,4 };
	int *ptr = &arr[0][0];

	for (int i = 0;i < 4;i++)
	{
		cout << endl << *ptr++;
	}
}
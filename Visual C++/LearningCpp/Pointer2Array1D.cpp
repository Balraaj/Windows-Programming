/*This program shows how pointer to array can be used to access elements of one dimensional array*/
#include<iostream>
using namespace std;

void main()
{
	int arr[3] = { 1,2,3 };
	int(*ptr)[3];

	ptr = &arr;
	cout << (*ptr)[0]<<endl;
	cout << (*ptr)[1]<<endl;
	cout << (*ptr)[2];
}
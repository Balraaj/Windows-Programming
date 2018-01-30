#include<iostream>

using namespace std;

class RadixSort
{
public:

	static int* csort(int arr[], int exp, int n)
	{
		int *C = new int[10];
		int *B = new int[n];

		for (int i = 0;i < 10;i++)
		{
			C[i] = 0;
		}

		for (int i = 0;i < n;i++)
		{
			C[arr[i] / exp % 10]++;
		}

		for (int i = 1;i < 10;i++)
		{
			C[i] = C[i] + C[i - 1];
		}

		for (int i = n-1;i >=0;i--)
		{
			B[C[arr[i] / exp % 10] - 1] = arr[i];
			C[arr[i] / exp % 10]--;
		}

		return B;
	}

	static int* sort(int arr[], int n)
	{
		int m = 0;
		int exp = 1;

		for (int i = 0;i < n;i++)
		{
			if (arr[i] > m)
			{
				m = arr[i];
			}
		}

		while (m / exp > 0)
		{
			arr = csort(arr, exp, n);
			exp *= 10;
		}
		return arr;
	}
};


int main()
{
	int arr[] = { 12,2,34,34,67,8,12,232,56,3,8,1 };
	
	cout << "Original array : \n\n";
	for (int i = 0;i < 12;i++)
	{
		cout << " " << arr[i];
	}

	cout << "\n\nArray after sorting : \n\n";

	int *temp = RadixSort::sort(arr, 12);
	for (int i = 0;i < 12;i++)
	{
		cout << " " << temp[i];
	}

	cout << endl;


}
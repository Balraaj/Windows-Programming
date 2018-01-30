#include<iostream>

using namespace std;

class CountingSort
{
public:
	static int* sort(int arr[],int max, int n)
	{
		int *C = new int[max + 1];
		int *B = new int[n];

		for (int i = 0;i < max + 1;i++)
		{
			C[i] = 0;
		}

		for (int i = 0;i < n;i++)
		{
			C[arr[i]]++;
		}

		for (int i = 1;i < max + 1;i++)
		{
			C[i] = C[i] + C[i - 1];
		}

		for (int i = n - 1;i >= 0;i--)
		{
			B[C[arr[i]] - 1] = arr[i];
			C[arr[i]]--;
		}

		return B;
	}

	
};

int main()
{
	int arr[] = { 12,34,1,2,6,78,6,6,2,1 };

	cout << "Original array : \n\n";
	for (int i = 0;i < 10;i++)
	{
		cout << " " << arr[i];
	}

	int *temp = CountingSort::sort(arr, 78, 10);

	cout << "\nArray after sorting : \n";
	for (int i = 0;i < 10;i++)
	{
		cout << " " << temp[i];
	}


}
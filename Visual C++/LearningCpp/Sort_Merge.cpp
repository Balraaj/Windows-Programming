/* This program implements the merge sort algorithm*/
#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int *, int *, int *, int, int);
void sort(int size, int *p)
{
	if (size < 2)
	{
		return;
	}

	int n = size / 2;
	int m = size - n;
	int k = 0;
	int *left = new int[n];
	int *right = new int[m];

	for (int i = 0;i < n;i++)
	{
		left[i] = p[k];
		k++;
	}

	for (int i = 0;i < m;i++)
	{
		right[i] = p[k];
		k++;
	}

	sort(n, left);
	sort(m, right);
	merge(left, right, p,n,m);
}

void merge(int *left, int *right, int *p,int n,int m)
{
	int x, y, z;
	x = y = z=0;

	while ((x < n) && (y < m))
	{
		if (left[x] < right[y])
		{
			p[z] = left[x];
			z++;
			x++;
		}
		else
		{
			p[z] = right[y];
			y++;
			z++;
		}
	}

	while (x < n)
	{
		p[z] = left[x];
			x++;
			z++;
	}
	while (y < m)
	{
		p[z] = right[y];
		y++;
		z++;
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

	for (int i = 0;i < 10;i++)
	{
		cout << "\n" << arr[i];
	}
}
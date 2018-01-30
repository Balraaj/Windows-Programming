/*This is a name sorting program which uses merge sort to sort the strings,maximum size of a name can be 10 characters*/
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int nocase(char a)
{
	//This function returns a capital character if a is small character
	if (a > 90)
	{
		return (a - 32);
	}
	else
	{
		return a;
	}
}

void cp(char *arr, char *arr1)
{
	//This function copies string from arr to arr1
	int i = 0;
	while (i < 10)
	{
		char c = arr[i];
		if (c == '\0') // break if end of the word is reached
		{
			break;
		}

		arr1[i] = arr[i];
		i++;

	}
	arr1[i] = '\0';
}

void stcpy(char *arr) 
{
	//This function reads string from console and write it to the arr
	int i = 0;
	while (i < 10)
	{
		char c = getchar();
		if (c == '\n') // break if enter is pressed
		{
			break;
		}
		arr[i++] = c;
	}
	arr[i] = '\0'; 
}

int comp(char *arr, char *arr1)
{
 /*This function compares two strings if arr is smaller (comes before arr1 when sorted) than it returns 1 other wise it returns -1*/
	int i = 0;
	int j = 0;
	bool flag = false;
	while ((i < 10) && (j < 10))
	{
		char a = nocase(arr[i]);
		char b = nocase(arr1[j]);
		if (a < b)
		{
			flag = true;
			break;
		}
		else if (a > b)
		{
			flag = false;
			break;
		}
		else
		{
			i++;
			j++;
		}
	}

	if (flag)
	{
		return 1; //Return 1 if arr is smaller than arr1
	}
	else
	{
		return -1; //Return -1 otherwise
	}
}

void Merge(char **arr, char **arr1, char **arr2,int n,int m)
{
	//This function combines the two strings together
	int i, j, k;
	i = j = k = 0;

	while ((i < n) && (j < m))
	{
		int flag = comp(arr1[i], arr2[j]);
		
		if (flag == 1)
		{
			cp(arr1[i], arr[k]);
			k++;
			i++;
		}
		else
		{
			cp(arr2[j], arr[k]);
			j++;
			k++;
		}

	}

	while (i < n)
	{
		cp(arr1[i], arr[k]);
		k++;
		i++;
	}
	while (j < m)
	{
		cp(arr2[j], arr[k]);
		k++;
		j++;
	}
}

void lexsort(char **arr, int size)
{
	// This is merge sort for strings
	if (size > 1)
	{
		int n = size / 2;
		int m = size - n;
		int k = 0;
		char **arr1 = (char**)malloc(n * sizeof(char*));
		char **arr2 = (char**)malloc(m * sizeof(char*));

		for (int i = 0;i < n;i++)
		{
			arr1[i] = (char*)malloc(11 * sizeof(char));
			cp(arr[k++], arr1[i]);
		}

		for (int i = 0;i < m;i++)
		{
			arr2[i] = (char*)malloc(11 * sizeof(char));
			cp(arr[k++], arr2[i]);
		}

		lexsort(arr1, n);
		lexsort(arr2, m);
		Merge(arr, arr1, arr2,n,m);

	}

}

int main()
{
    char **arr = (char**)malloc(6 * sizeof(char*));
		
	for (int i = 0;i < 6;i++)
	{
		arr[i] = (char*)malloc(11 * sizeof(char));
	}

	for (int i = 0;i < 6;i++)
	{
		char *ptr = arr[i];
		printf("\nEnter a name of 10 chars : ");
		stcpy(ptr);
	}

	for (int i = 0;i < 6;i++)
	{
		printf("\nName is : %s", arr[i]);
	}

	lexsort(arr, 6);

	printf("\n\nAfter sorting : ");

	for (int i = 0;i < 6;i++)
	{
		printf("\nName is : %s", arr[i]);
	}

}

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "stdafx.h"
int main(void)
{
	int arr[10];
	int fixstrt, fixend, strt, end, i, s, t, store;
	fixstrt = fixend = strt = end = i = s = t = store = 0;
	printf("Enter the array: ");
	for (; i < 10; i++)
	{

		scanf("%d", &arr[i]);
	}
	i = 0;
	while (i < 10)
	{
		int temp = 0;
		t = arr[i];
		temp = t + s;
			
		if (temp < s)
		{
			
			if (store < s)
			{
				store = s;
				fixend = i - 1;
				fixstrt = strt;
				strt = i + 1;
				s = 0;
				i++;
				continue;
			}
			strt = i + 1;
			s = 0;
			i++;
			continue;
        }
		s = temp;
		
		i++;
	}
	if (s > store)
	{
		store = s;
		fixstrt = strt;
		fixend = i - 1;
	}

	printf("\nMaximum value of contiguos array = %d", store);
	printf("\n\nLocation of array is %d to %d", fixstrt, fixend);

	return 0;

}
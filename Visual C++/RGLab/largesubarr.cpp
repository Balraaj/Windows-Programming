//program to find maximum subarray
#include <stdio.h>

// see http://stackoverflow.com/a/7943955/7507

int main() {

	int best = 0;
	int bestNow = 0;
	int Start = -1;
	int Stop = -1;
	int StartNow = -1;

	int array[] = { 4, -3, 9, -6, -9 };
	int array_len = sizeof(array) / sizeof(int);

	for (int i = 0; i < array_len; i++) 
	{
		int value = bestNow + array[i];

		if (value > 0)  
		{
			if (bestNow == 0) 
			{
				StartNow = i;
			}
			bestNow = value;
		}
		else 
		{
			bestNow = 0;
		}

		if (bestNow > best) 
		{
			best = bestNow;
			Stop = i;
			Start =StartNow;
		}
	}

	printf("Best Sum = %d\n", best);
	printf("Max Array = [");

	for (int i = Start; i < Stop + 1; i++) {
		printf(" %d", array[i]);
	}

	printf(" ]\n");

}
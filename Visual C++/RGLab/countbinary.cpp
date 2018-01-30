//This program counts possible no. of binary trees for n nodes
#include<stdio.h>
int countTree(int N)
{
	if(N == 0 || N == 1)
		return 1;
	int sum = 0, left = 0, right = 0;
	for(int k = 1; k <= N; k++)
	{
		left = countTree(k - 1);
		right = countTree(N - k);
		sum += left*right;
	}
	return sum;
}

void main()
{
	int n;
	printf("Enter no. of nodes = ");
	scanf("%d", &n);
	int z =	countTree(n);
	printf("No. of trees = %d", z);
}
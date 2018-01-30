#include<iostream>
using namespace std;

int ATOI(char x)
{
	return x - 48;
}

void main()
{
	char x = '1';
	int value = ATOI(x);
	printf("%d", value);
}
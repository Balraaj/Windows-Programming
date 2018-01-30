//This program shows use of function pointers 

#include<stdio.h>

typedef float(*p)(int, int);

float sum(int x, int y)
{
	 float z = x + y;
	 return z;
}

float mul(int x, int y)
{
	float z = x*y;
	return z;
}

float min(int x, int y)
{
	float z = x - y;
	return z;
}

p choose(int x)
{
	p ptr;
	switch (x)
	{
	case 1: 
		ptr = sum;
		return ptr;
	case 2:
		ptr = mul;
		return ptr;
	case 3:
		ptr = min;
		return ptr;
	}
}

int main()
{
	int n;
	printf("What operation you want to perform : \n 1 for sum \n 2 for multiply \n 3 for minus\n");
	scanf("%d",&n);
	p ptr = choose(n);


	printf("\nResult of operation is = %f ",(*ptr)(10, 20));
	

}
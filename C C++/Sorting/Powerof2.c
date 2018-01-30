#include<stdio.h>
int checkPower(int x)
{
	return (x!=0)&&((x&(x-1))==0);
}

void main(int argc, char** argv)
{
	printf("%d is power of 2 : %d",argc,checkPower(argc));
}

	

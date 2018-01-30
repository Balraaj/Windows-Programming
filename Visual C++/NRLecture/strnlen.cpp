#include<stdio.h>
#include<conio.h>
int strnlen(char *);
int main(void)
{
	char arr[100];
	printf("Enter your array :[Type EXIT to stop] \n ");
	scanf("%[^EXIT]s", arr);

	int z = strnlen(arr);
	printf("\nLength of your string = %d", z);
	
	return 0;
}


int strnlen(char *x)
{
	int count = 0;
	while (*x!='\0')
	{
		count++;
		x++;
	}

	return count;
}
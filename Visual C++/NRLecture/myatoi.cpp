
#include<stdio.h>
#include<conio.h>
int main(void)
{
	char arr[10];
	printf("Enter your string = ");
	scanf("%s", arr);
	int i = 0;
	int value = 0;
	while (arr[i] != '\0')
	{
		value = value * 10 + arr[i] - '0';
		i++;
	}

	printf("\nValue = %d", value);
	return 0;

}
#include<stdio.h>
#include<conio.h>
void stringchng(char []);
int main(void)
{
	char arr[100];
	printf("Enter your string:\n");
	scanf("%[^\t]s", arr);

	stringchng(arr);

	printf("\n\nValue of your string is changed = %s", arr);
	return 0;
}

void stringchng(char x[])
{
	x = "hello this is balraj";
}
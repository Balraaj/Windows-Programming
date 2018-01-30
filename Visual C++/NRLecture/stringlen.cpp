#include<stdio.h>
#include<conio.h>
int stringlen(char *);
int main(void)
{
	char arr[100];
	int i = 0;
	printf("Enter your array = ");
	while (1)
	{
		char c = getchar();
		if (c == '\n')
			break;
		arr[i++] = c;
	}
	arr[i] = '\0';
	int z = stringlen(arr);
	printf("\nLength of string = %d", z);
	getch();
	return 0;
}

int stringlen(char *x)
{
	int len = 0;
	while (*x != '\0')
	{
		len++;
		x++;
	}

	return len;
}
#include<stdio.h>
#include<conio.h>
void strconcat(char *, char *);
int main(void)
{
	char arr[500];
	char str[500];
	printf("Enter your first string = ");
	scanf("%[^EXIT]s", arr);
	fflush(stdin);
	printf("Enter your second string = ");
	scanf("%[^EXIT]s", str);

	strconcat(arr, str);
	return 0;
}

void strconcat(char *x, char *y)
{
	char temp[500];
	int i = 0;
	while (x[i] != '\0')
	{
		temp[i] = x[i];
		i++;
	}
	int j = 0;
	while (y[j] != '\0')
	{
		temp[i++] = y[j++];

	}
	temp[i] = '\0';
	printf("\nConcated string = %s", temp);
}
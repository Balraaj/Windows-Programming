#include<stdio.h>
#include<conio.h>
void strncpy(char *, char *);
int main(void)
{
	char arr[100];
	char temp[100];
	printf("Enter String = ");
	scanf("%[^EXIT]s", arr);

	strncpy(arr, temp);
	printf("\nContents of temp %s", temp);
	return 0;
}


void strncpy(char *x, char *y)
{
	int i = 0;
	while (x[i] != '\0')
	{
		y[i] = x[i];
		i++;
	}
	y[i] = '\0';
}
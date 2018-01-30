#include<stdio.h>
#include<conio.h>
void strnrev(char *);
int main(void)
{
	char arr[100];
	printf("Enter your string = ");
	scanf("%[^\t]s", arr);
	strnrev(arr);
	printf("\nReverse string = %s", arr);
	return 0;

}


void strnrev(char *x)
{
	int i = 0, j = 0;
	while (x[i] != '\0')
	{
		i++;
		j++;
	}
	i = 0;
	j--;

	while (i<j)
	{
		char temp;
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
		i++;
		j--;
	}

}
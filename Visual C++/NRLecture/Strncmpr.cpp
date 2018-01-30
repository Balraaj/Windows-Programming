#include<stdio.h>
#include<conio.h>
int strncmpr(char *, char *);
int main(void)
{
	char arr[100];
	char str[100];
	printf("Enter string 1 = ");
	scanf("%[^EXIT]s", arr);
	fflush(stdin);



	printf("\nEnter string 2 = ");
	scanf("%[^EXIT]s", str);

	int z = strncmpr(arr, str);
	printf("value of z = %d", z);
	return 0;



}

int strncmpr(char *x, char *y)
{
	int i = 0;
	while (x[i] != '\0')
	{
		
		if (x[i] == y[i])
		{
			i++;
			continue;
		}
		else	if (x[i] < y[i])
			return -1;
		else	if (x[i] > y[i])
			return 1;

		i++;

	}
	printf("\nStrings are equal ");
	return 0;
}










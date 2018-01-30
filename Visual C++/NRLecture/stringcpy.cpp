#include<stdio.h>
#include<conio.h>
void stringcpy(char *s, char *t);
int main(void)
{
	char arr[20], temp[20];
	printf("Enter your string = ");
	int i = 0;
	scanf("%[^\t]s", arr);
	//arr[i] = '\0';
	stringcpy(arr, temp);
	printf("\n\nContents of temp = %s", temp);
	return 0;

}

void stringcpy(char *s, char *t)
{
	int i = 0;
	while ((t[i]=s[i])!='\0')
	{
		i++;
	}
}
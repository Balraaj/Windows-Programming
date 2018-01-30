#include<stdio.h>
#include<conio.h>
int strnlen(char *);
void strsrch(char *, char *);
int main(void)
{
	char arr[100];
	char wrd[15];
	printf("Enter your string = ");
	scanf("%[^EXIT]s",arr);
	fflush(stdin);
	printf("\n\nEnter word to search = ");
	scanf("%s",wrd);

	strsrch(wrd, arr);
	return 0;

}

void strsrch(char *x, char *y)
{
	
	int i = 0, j = 0;
	int k= strnlen(x);
	while (y[i] != '\0')
	{ 
		if (x[j] == y[i])
		{
			i++;
			j++;
			continue;
		}
		
		
		if (x[j] != y[i] && j < k)
		{
			j = 0;
			i++;
			continue;
		}
	   
		if (x[j] == '\0')
			break;
		
	}
	if (x[j] == '\0')
		printf("\nword found");
	else
		printf("\nword not found");
}

int strnlen(char *x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		++i;
	}
	return i;
}
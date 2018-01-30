#include<stdio.h>
#include<conio.h>
void strsrch(char *, char *);
void main()
{
	char arr[100], str[100];
	printf("Enter first string : ");
	scanf("%s", arr);
	printf("\nEnter second string : ");
	scanf("%s", str);
	strsrch(arr, str);
	getch();
}

void strsrch(char *x, char *y)
{
	int i, j, start;
	i = j = start = 0;
	while (x[i] != '\0')
	{
		if (y[j] == '\0')
			break;
		if (x[i] == y[j])
		{
			if(j == 0)
			{
				start = i;
			}

			i++;
			j++;
			continue;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (y[j] == '\0')
		printf("pattern found at %d", start);
	else
		printf("pattern not found");
}
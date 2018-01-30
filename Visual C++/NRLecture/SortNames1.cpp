#include<stdio.h>
#include<conio.h>
int strcmpr(char *, char *);
void strcpy(char *, char *);
int main(void)
{
	char arr[10][10], str[10][10],temp[10];
	int n = 0;
	int z = 0;
	printf("How many names you want to enter = ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
		strcpy(&arr[i][0], &str[i][0]);
	}
	
	for (int i = 0; i < n-1; i++)
	{
		int k =strcmpr(arr[i], arr[i + 1]);
		if (k < 0)
		{
			strcpy(&arr[i][0], temp);
			strcpy(&arr[i + 1][0], &arr[i][0]);
			strcpy(temp, &arr[i][0]);

		}


	}

	printf("after sortin :::");
	for (z; z < n; z++);
	{
		strcpy(arr[z], temp);
		printf("%s", temp);
	}
}

int strcmpr(char *str1, char *str2)
{
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}

	if (*str1 > *str2)
		return 1;

	if (*str1 < *str2)
		return -1;

	return 0;
}


void strcpy(char *x, char *y)
{
	int i = 0;
	while (x[i] != '\0')
	{
		y[i] = x[i];
		i++;

	}
	y[i] = '\0';
}
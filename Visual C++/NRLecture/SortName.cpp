#include <stdio.h>
int strncmpr(char *, char *);
void strncpy(char *, char *);
int main(void)
{
	char name[100][8], tname[100][8], temp[8];
	int i, j, n;

	printf("Enter the value of n \n");
	scanf("%d", &n);
	printf("Enter %d names \n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		strncpy(name[i],tname[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strncmpr(name[i], name[j]) > 0)
			{
				strncpy(name[i],temp);
				strncpy(name[j],name[i]);
				strncpy(temp, name[j]);
			}
		}
	}
	printf("\n----------------------------------------\n");
	printf("Input NamestSorted names\n");
	printf("------------------------------------------\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t\t%s\n", tname[i], name[i]);
	}
	printf("------------------------------------------\n");
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
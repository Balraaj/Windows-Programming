//PROGRAM TO COUNT NO. OF WORDS , LINES, CHARACTERS 

#include<stdio.h>
#include<conio.h>
void wordcount(char *);
void main()
{
	char arr[400];
	printf("Enter you string = ");
	scanf("%[^EX]s", arr);
	wordcount(arr);
	getch();
}


void wordcount(char *x)
{
	int nw, nl, nc, state ;
	nw = nl = nc = state = 0;
	while (*x != '\0')
	{
		nc++;

		if (*x == ' ' || *x == '\n' || *x == '\t')
		{
			if (*x == '\n')
			{
				nl++;
			}
			state = 0;
		}
		else if (state == 0)
		{
			nw++;
			state = 1;
		}
		x++;

	}

	printf("\n\nLines\tWords\tChars\n\n");
	printf("%d\t%d\t%d", nl, nw, nc);
}
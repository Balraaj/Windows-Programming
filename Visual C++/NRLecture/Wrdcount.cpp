#include<stdio.h>
#include<conio.h>
void wrdcount(char *);
int main()
{
	char arr[1000];
	printf("Enter your string = ");
	scanf("%[EXIT]s", arr);

	wrdcount(arr);
	return 0;


}


void wrdcount(char *x)
{
	int nw, nc, nl,state;
	nw =  nc = nl=state = 0;
	
	while (*x != '\0')
	{
		nc++;
		


		if (*x == '\n' || *x == ' ' || *x == '\t')
		{
			if (*x == '\n')
			{
				++nl;

			}
              
				state = 0;
        }

		else if (state == 0)
		{
			state = 1;
			++nw;
		}

		x++;

	}


	printf("\n\nWords\tlines\tChars");
	printf("\n%d\t%d\t%d", nw, nl, nc);
}
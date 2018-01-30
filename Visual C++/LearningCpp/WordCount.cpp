/* This program counts no of words,characters,lines in a given sentence and prints output
   use ctrl+z and then enter to stop the program*/
#include<iostream>
using namespace std;

void main()
{
	int nw, nc, nl;
	bool state=false;
	nc = nw = nl = 0;

	char z = getchar();
	while (z!=EOF)
	{
		nc++;

		if ((z == ' ') || (z == '\t') || (z == '\n'))
		{
			state = false;
			nc--;

			if (z == '\n')
			{
				nl++;
			}
			
		}
		
		if((state==false)&&(z!=' ')&&(z!='\t')&&(z!='\n'))
		{
			nw++;
			state = true;
		}
		z = getchar();
	}

	printf("\nCharacters : %d", nc);
	printf("\nWords : %d", nw);
	printf("\nLines : %d", nl);

}
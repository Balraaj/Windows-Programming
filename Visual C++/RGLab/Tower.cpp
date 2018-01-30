#include<stdio.h>
#include<conio.h>
int count = 0;
void tower(int, char, char, char);
int main(void)
{
	int n;
	printf("\nEnter no. of disks = ");
	scanf("%d", &n);
	printf("\n\nMoves involved :\n");
	tower(n, 'a', 'c', 'b');
	printf("\nTotal no of moves = %d", count);
	getch();
	return 0;
}

void tower(int n, char a, char c, char b)
{
	if (n == 1)
	{
		printf("\nMoved disk 1 from %c to %c", a, c);
		count++;
		return;
	}

	tower(n - 1, a, b, c);
	printf("\nMoved disk %d from %c to %c", n, a, c);
	count++;
	tower(n - 1, b, c, a);
	
}
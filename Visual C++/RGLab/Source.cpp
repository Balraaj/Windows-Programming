#include<stdio.h>
typedef struct node* ptr;
struct node
{
	char vertex;
	ptr next;
};

void main()
{
	node list[5];
	list[0].vertex = 'A';
	list[1].vertex = 'B';
	list[2].vertex = 'C';
	list[3].vertex = 'D';
	list[4].vertex = 'E';

	for (int i = 0;i < 5;i++)
	{
		printf("\n\nVertex = %c", list[i].vertex);
	}
	getchar();
}
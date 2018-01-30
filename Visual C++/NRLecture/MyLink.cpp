//This program implements a linked list
#include<stdlib.h>
#include<stdio.h>
void add(int);
void addpos(int, int);
void print();
int remove(int);
typedef struct node *ptr;
typedef node node;
struct node{
	int value;
	ptr next;
};
ptr start, current;
int main()
{
	int n,val;
	start = (ptr)malloc(sizeof(node));
	start->value = 0;
	start->next = NULL;
	printf("\nHow many values you want to enter = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter value = ");
		scanf("%d", &val);
		add(val);
	}

	print();
	printf("\n\nHow many values you want to delete = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter value to delete = ");
		scanf("%d", &val);
		int x=remove(val);
		if (x < 0)
			i--;
	}
	print();

}

void add(int x)
{
	ptr temp = (ptr)malloc(sizeof(node));
	temp->next = NULL;
	temp->value = x;
	if (start->value == 0)
	{
		++start->value;
		start->next = temp;
		current = temp;
	}
	else
	{
		++start->value;
		current->next = temp;
		current = temp;
	}
}



void addpos(int x, int y)
{
	if (x == (start->value + 1))
	{
		add(y);
	}
	else
	{
		int i=0;
		ptr prev = start;
		
		while (i < (x-1))
		{
			prev = prev->next;
			i++;
		}
		ptr temp = (ptr)malloc(sizeof(node));
		temp->value = y;
		temp->next = prev->next;
		prev->next = temp;
		++start->value;
	}
}

int remove(int x)
{
	
	ptr run = start->next;
	ptr prev=start;
	while (run->value != x)
	{
		prev = run;
		run = run->next;
		if (run->next == NULL)
		{
			break;
		}
	}
	if ((run->value != x) && (run->next == NULL))
	{
		printf("\nValue not found\n\n");
		return -1;
	}
	prev->next = run->next;
	free(run);
	--start->value;
	return 0;
	
	
}

void print()
{
	ptr run = start->next;
	int i = 0;
	for (; i < start->value; i++)
	{
		printf("\n%d", run->value);
		run = run->next;
	}
	printf("\n\n\n");
}
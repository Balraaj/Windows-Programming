#include<stdio.h>
#include<stdlib.h>


struct node
{
	int value;
	node *next;
};

node *start, *end;

void push(int x)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->value = x;
	if (start == nullptr)
	{
		start = end = temp;
	}

	else
	{
		end->next = temp;
		end = temp;
	    end->next = nullptr;
	}
}

void pop()
{
	node *run;
	run = start;
	while (run->next != end)
	{
		run = run->next;
	}

	end = run;
	free(end->next);
	end->next = nullptr;

}

void disp()
{
	node *run;
	run = start;
	while (run != nullptr)
	{
		printf("\nValue : %d ", run->value);
		run = run->next;
	}
}

void main()
{
	start = end = nullptr;
	for (int i = 0;i < 10;i++)
	{
		push(i);
	}

	printf("\n");
	disp();

	for (int i = 0;i < 3;i++)
	{
		pop();
	}

	printf("\n");
	disp();

}
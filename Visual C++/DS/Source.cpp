#include<stdio.h>
#include<stdlib.h>

int* createnode(int value)
{
	int *temp = (int*)malloc(sizeof(int));
	*temp = value;
	return temp;

}

void add(int *ptr, int value)
{
	if (ptr == NULL)
	{
		int *temp = createnode(value);
		ptr = temp;
	}
}

int main()
{
	int *root = NULL;
	add(root, 1);
	printf("%d", *root);
}
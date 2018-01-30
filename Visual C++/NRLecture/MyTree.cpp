#include<stdio.h>
#include<stdlib.h>
#include<queue>

typedef struct treenode treenode;
typedef treenode *treeptr;

struct treenode{
	int value;
	treeptr left;
	treeptr right;
};
treeptr root;

treeptr newnode(int data)
{
	treeptr temp = (treeptr)malloc(sizeof(treenode));
	temp->left = temp->right = NULL;
	temp->value = data;
	return temp;
}



void insert(int x)
{

	treeptr temp = root;
	while (1)
	{

		if (x > temp->value)
		{
			if (temp->right == NULL)
			{
				break;
			}
			temp = temp->right;
		}
		else
		{
			if (temp->left == NULL)
			{
				break;
			}
			temp = temp->left;
		}
	}
	if (x > temp->value)
	{
		temp->right = newnode(x);
	}
	else if (x <= temp->value)
	{
		temp->left = newnode(x);
	}
}

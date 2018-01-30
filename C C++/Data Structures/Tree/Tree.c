/*
 * Tree.c
 *
 *  Created on: 14-Jul-2016
 *      Author: Balraj
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct treenode node;
typedef struct mytree tree;

struct mytree
{
	node *root;
	bool status;
};

struct treenode
{
	int value;
	node *left;
	node *right;
	node *parent;
};

tree* new_tree()
{
	tree *temp = (tree*)malloc(sizeof(tree));
	temp->root = NULL;
	temp->status = true;
	return temp;
}
node* createnode(int value)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr->left = ptr->right = ptr->parent = NULL;
	ptr->value = value;
	return ptr;
}

void add(node *ptr,int value)
{
	node *prev = NULL;
	bool flag = true;
	while (ptr != NULL)
	{
		if (value < ptr->value)
		{
			flag = true;
			prev = ptr;
			ptr = ptr->left;
		}
		else
		{
			flag = false;
			prev = ptr;
			ptr = ptr->right;
		}
	}

	node *temp = createnode(value);
	temp->parent = prev;
	if (flag)
	{
		prev->left = temp;
	}
	else
	{
		prev->right = temp;
	}
}

void treeadd(tree* ptr, int value)
{
	if (ptr->root == NULL)
	{
		ptr->root = createnode(value);
		ptr->status = false;
		return;
	}
	else
	{
		add((ptr->root), value);
	}
}

void inorder(node *ptr)
{
	if (ptr != NULL)
	{
		inorder(ptr->left);
		printf(" %d", ptr->value);
		inorder(ptr->right);
	}
}

node* position(node *ptr, int value)
{
	if (ptr == NULL)
	{
		printf("\nSorry,The value doesn't exist in the tree");
		return NULL;
	}
	else if (value < ptr->value)
	{
		return position(ptr->left, value);
	}
	else if (value > ptr->value)
	{
		return position(ptr->right, value);
	}
	else
	{
		return (ptr);
	}

}

int nodetype(node *ptr)
{
	if (ptr->parent == NULL)
	{
		return 1;
		//root
	}
	else if ((ptr->left == NULL) && (ptr->right == NULL))
	{
		return 2;
		//leaf node
	}
	else if (ptr->left == NULL)
	{
		return 3;
		//internal node with right child
	}
	else if (ptr->right == NULL)
	{
		return 4;
		//internal node with left child
	}
	else
	{
		return 5;
		//internal node with left and right childs
	}

}

int childtype(node *ptr)
{
	node *temp = ptr->parent;

	if (temp->left == ptr)
	{
		return 1;
		//left child
	}
	else if (temp->right == ptr)
	{
		return 2;
		//right child
	}
	else
	{
		return -1;
	}
}

void delntype2(node *ptr)
{
	//this function deletes a leaf node
	node *temp = ptr->parent;
	int var = childtype(ptr);

	if (var == 1)
	{
		temp->left = NULL;
	}
	else if (var == 2)
	{
		temp->right = NULL;
	}

	free(ptr);

}

void delntype3(node *ptr)
{
	//this function deletes a internal node having only right child
	node *temp = ptr->parent;
	int var = childtype(ptr);
	if (var == 1)
	{
		temp->left = ptr->right;
	}
	else if (var == 2)
	{
		temp->right = ptr->right;
	}
	ptr->right->parent=temp;
	free(ptr);
}

void delntype4(node *ptr)
{
	//this function delete an internal node having only left child
	node *temp = ptr->parent;
	int var = childtype(ptr);
	if (var == 1)
	{
		temp->left = ptr->left;
	}
	else if (var == 2)
	{
		temp->right = ptr->left;
	}
	ptr->left->parent=temp;
	free(ptr);
}

void delntype5(node *ptr)
{
	//this function deletes an internal node having left and right childs
	node *temp = ptr->parent;
	int var = childtype(ptr);

	if (var == 1)
	{
		temp->left = ptr->right;
		temp->left->parent = temp;
		node *branch = ptr->left;

		node *run = ptr->right;
		while (run->left != NULL)
		{
			run = run->left;
		}

		run ->left = branch;
		branch->parent=run;
		free(ptr);
	}
	else if (var == 2)
	{
		temp->right = ptr->right;
		temp->right->parent = temp;
		node *branch = ptr->left;

		node *run = ptr->right;
		while (run->left != NULL)
		{
			run = run->left;
		}

		run->left = branch;
		branch->parent=run;
		free(ptr);
	}
}

void rm(node *ptr)
{
	int var = nodetype(ptr);

	switch (var)
	{
	case 1:
		break;
	case 2:
		delntype2(ptr);
		break;
	case 3:
		delntype3(ptr);
		break;
	case 4:
		delntype4(ptr);
		break;
	case 5:
		delntype5(ptr);
		break;
	default:
		break;

	}
}

bool isempty(tree *ptr)
{
	return ptr->status;
}

void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf(" %d",ptr->value);
	}
}

bool contains(node *ptr,int value)
{
	if(ptr==NULL)
	{
		return false;
	}
	else if(ptr->value==value)
	{
		return true;
	}
	else if(value<ptr->value)
	{
		return contains(ptr->left,value);
	}
	else if(value>ptr->value)
	{
		return contains(ptr->right,value);
	}
	else
	{
		return true;
	}
}



int main()
{
	tree *obj = new_tree();

	int arr[20] = { 100,50,200,25,75,150,250,12,45,65,85,125,175,225,275,6,15,35,48,500 };

	for (int i = 0;i < 20;i++)
	{
		treeadd(obj, arr[i]);
	}

	printf("Inorder traversal is : \n\n");
	inorder(obj->root);

	printf("\n\nPostorder traversal is : \n\n");
	postorder(obj->root);

	bool flag=contains(obj->root,7);
	printf("\n\nTree contains %d : %d",7,flag);
	return 0;
}



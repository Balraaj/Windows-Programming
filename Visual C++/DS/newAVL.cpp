#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "newAVL.h"

struct treenode
{
	int value;
	int height;
	node *left;
	node *right;
	node *parent;
};

struct mytree
{
	node *root;
	bool status;
};

// functions provided by ADT

tree* new_tree()
{
	// constructor function for tree
	tree *temp = (tree*)malloc(sizeof(tree));
	temp->root = NULL;
	temp->status = true;
	return temp;
}

node* getposition(node *ptr, int value)
{
	/*Return address of the node having value equal to "value", returns NULL if not found
	ptr should be root of tree*/
	if (ptr == NULL)
	{
		return NULL;
	}
	else if (value < ptr->value)
	{
		return getposition(ptr->left, value);
	}
	else if (value > ptr->value)
	{
		return getposition(ptr->right, value);
	}
	else
	{
		return (ptr);
	}

}

node* parent(tree *obj, int value)
{
	//Returns parent of "ptr"
	node *ptr = getposition(obj->root, value);
	if (ptr)
	{
		return ptr->parent;
	}
	else
	{
		return NULL;
	}
}

bool isempty(tree *obj)
{
	return obj->status;
}

node* leftchild(tree *obj, int value)
{
	//Returns leftchild of "ptr"
	node *ptr = getposition(obj->root, value);
	if (ptr)
	{
		return ptr->left;
	}
	else
	{
		return NULL;
	}
}

node* rightchild(tree *obj, int value)
{
	//Returns right child of "ptr"
	node *ptr = obj->root;
	if (ptr)
	{
		return ptr->right;
	}
	else
	{
		return NULL;
	}
}

void add(tree *obj, int value)
{
	// adds "value" to the tree, value must not be a member of set S. where S is set of all values
	// stored in tree

	if (obj->root == NULL)
	{
		node *temp = createnode(value);
		obj->root = temp;
		obj->status = false;
	}
	else
	{
		node *ptr = obj->root;
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

		balance(obj, temp);
	}
}

void rmroot(tree *obj)
{
	//Removes root node of tree
	if (obj->root)
	{
		rem(obj, obj->root);
	}
}

void rmnode(tree *obj, int value)
{
	//Removes node having value equal to "value" . no operation is performed if such a node is not found
	node *temp = getposition(obj->root, value);
	if (temp)
	{
		rem(obj, temp);
	}
}

void searchvalue(tree *obj, int value)
{
	//search the tree for value
	node *temp = getposition(obj->root, value);
	if (temp)
	{
		printf("\n\nValue found\n\n");
	}
	else
	{
		printf("\n\nValue not found\n\n");
	}
}

void inorder(tree *obj)
{
	/*Performs inorder traversal of tree*/
	node *ptr = obj->root;
	printf("\nInorder Traversal : ");
	intraverse(ptr);
	printf("\n\n");

}

void postorder(tree *obj)
{
	//Performs post order traversal of tree rooted at ptr
	printf("\nPostorder Traversal : ");
	node *ptr = obj->root;
	posttraverse(ptr);
	printf("\n\n");
}


// Helper functions for the ADT functions

static void posttraverse(node *ptr)
{
	if (ptr)
	{
		posttraverse(ptr->left);
		posttraverse(ptr->right);
		printf(" %d", ptr->value);
	}
}

static void intraverse(node *ptr)
{
	if (ptr)
	{
		intraverse(ptr->left);
		printf(" %d", ptr->value);
		intraverse(ptr->right);
	}
}

static void rem(tree *obj, node *ptr)
{
	/*Deletes node given by "ptr"*/

	int var = nodetype(ptr);
	node *father = ptr->parent;

	switch (var)
	{
	case TYPEONE:
		delntype1(obj);
		break;
	case TYPETWO:
		delntype2(ptr);
		break;
	case TYPETHREE:
		delntype3(ptr);
		break;
	case TYPEFOUR:
		delntype4(ptr);
		break;
	case TYPEFIVE:
		delntype5(obj, ptr);
		break;
	default:
		break;

	}

	if (father)
	{
		if (isheightchanged(father))
		{
			setheight_toroot(father);
		}
		while (father)
		{
			if (isunbalanced(father))
			{
				rearrange(obj, father);
				setheight_toroot(father);
			}
			father = father->parent;
		}
	}
}

static node* createnode(int value)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->left = ptr->right = ptr->parent = NULL;
	ptr->value = value;
	ptr->height = 0;
	return ptr;
}

static int getheight(node *ptr)
{
	if (ptr == NULL)
	{
		return NULLHEIGHT;
	}
	else
	{
		return ptr->height;
	}
}

static void setheight_toroot(node *ptr)
{
	setheight(ptr, NULL);
}

static void setheight(node *start, node *stop)
{
	//sets height of nodes beggining from start to stop(excluding)
	while (start != stop)
	{
		start->height = findmax(getheight(start->right), getheight(start->left)) + 1;
		start = start->parent;
	}

}

static int getbalfac(node *ptr)
{
	//Returns balance factor of a node
	if (ptr)
	{
		return (-(getheight(ptr->left)) + (getheight(ptr->right)));
	}
	else
	{
		return 0;
	}
}

static node* findpredecessor(tree *obj, node *ptr)
{
	if (ptr)
	{
		node *run = ptr->left;
		node *father = ptr->parent;
		if (run)
		{
			while (run->right)
			{
				run = run->right;
			}
		}
		else if ((father) && (ptr->value > father->value))
		{
			run = ptr->parent;
		}
		else
		{
			if (ptr->value > obj->root->value)
			{
				run = obj->root;
			}
			else
			{
				run = NULL;
			}
		}
		return run;
	}
	else
	{
		return NULL;
	}
}

static bool isleftheavy(node *ptr)
{
	return (getheight(ptr->left) > getheight(ptr->right));
}

static bool isrightheavy(node *ptr)
{
	return (getheight(ptr->right) > getheight(ptr->left));
}

static bool isunbalanced(node *ptr)
{
	//Returns pointer to the first node which is unbalanced
	int var = getbalfac(ptr);
	if ((var < -1) || (var > 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

static bool isheightchanged(node *ptr)
{
	int first = ptr->height;
	int second = findmax(getheight(ptr->left), getheight(ptr->right)) + 1;

	if (first == second)
	{
		return false;
	}
	else
	{
		return true;
	}
}

static void rotateright(tree *obj, node *ptr)
{
	node *new_root = ptr->left;
	ptr->left = new_root->right;

	if (ptr->left)
	{
		ptr->left->parent = ptr;
	}

	new_root->right = ptr;

	node *father = ptr->parent;
	if (!father)
	{
		obj->root = new_root;
		new_root->parent = NULL;
	}
	else
	{
		int var = childtype(ptr);
		if (var == LEFTCHILD)
		{
			father->left = new_root;
		}
		else
		{
			father->right = new_root;
		}
		new_root->parent = father;
	}
	ptr->parent = new_root;

}

static void rotateleft(tree *obj, node *ptr)
{
	node *new_root = ptr->right;
	ptr->right = new_root->left;

	if (ptr->right)
	{
		ptr->right->parent = ptr;
	}

	new_root->left = ptr;

	node *father = ptr->parent;
	if (!father)
	{
		obj->root = new_root;
		new_root->parent = NULL;
	}
	else
	{
		int var = childtype(ptr);
		if (var == LEFTCHILD)
		{
			father->left = new_root;
		}
		else
		{
			father->right = new_root;
		}
		new_root->parent = father;
	}
	ptr->parent = new_root;
}

static void rearrange(tree *obj, node *ptr)
{
	if (isleftheavy(ptr))
	{
		if (isrightheavy(ptr->left))
		{
			ptr->left->right->height++;
			ptr->height -= 2;
			ptr->left->height--;
			rotateleft(obj, ptr->left);
			rotateright(obj, ptr);
		}

		else
		{
			ptr->height -= 2;
			rotateright(obj, ptr);
		}
	}

	else if (isrightheavy(ptr))
	{
		if (isleftheavy(ptr->right))
		{
			ptr->right->left->height++;
			ptr->height -= 2;
			ptr->right->height--;
			rotateright(obj, ptr->right);
			rotateleft(obj, ptr);
		}

		else
		{
			ptr->height -= 2;
			rotateleft(obj, ptr);
		}
	}
}

static void balance(tree *obj, node *ptr)
{
	if (isheightchanged(ptr->parent))
	{
		while ((ptr) && (!isunbalanced(ptr)))
		{
			setheight(ptr, ptr->parent);
			ptr = ptr->parent;
		}

		if (ptr)
		{
			setheight(ptr, ptr->parent);
			rearrange(obj, ptr);
		}
	}
}

static void delntype1(tree *obj)
{
	int var = roottype(obj->root);
	node *temp = NULL;
	switch (var)
	{
	case TYPETWO:
		// root is leaf
		free(obj->root);
		obj->root = NULL;
		obj->status = true;
		break;

	case TYPETHREE:
		//root has only right child
		temp = obj->root->right;
		free(obj->root);
		obj->root = temp;
		obj->root->parent = NULL;
		break;

	case TYPEFOUR:
		//root has only left child
		temp = obj->root->left;
		free(obj->root);
		obj->root = temp;
		obj->root->parent = NULL;
		break;

	case TYPEFIVE:
		//root has both childs
		delntype5(obj, obj->root);
		break;
	}
}

static void delntype2(node *ptr)
{
	//this function deletes a leaf node
	node *father = ptr->parent;
	int var = childtype(ptr);

	if (var == LEFTCHILD)
	{
		father->left = NULL;
	}
	else
	{
		father->right = NULL;
	}

	free(ptr);

}

static void delntype3(node *ptr)
{
	//this function deletes a internal node having only right child
	node *father = ptr->parent;
	int var = childtype(ptr);
	if (var == LEFTCHILD)
	{
		father->left = ptr->right;
	}
	else
	{
		father->right = ptr->right;
	}
	ptr->right->parent = father;
	free(ptr);
}

static void delntype4(node *ptr)
{
	//this function delete an internal node having only left child
	node *father = ptr->parent;
	int var = childtype(ptr);
	if (var == LEFTCHILD)
	{
		father->left = ptr->left;
	}
	else 
	{
		father->right = ptr->left;
	}
	ptr->left->parent = father;
	free(ptr);
}

static void delntype5(tree *obj, node *ptr)
{
	node *temp = findpredecessor(obj, ptr);
	int var = temp->value;
	rmnode(obj, temp->value);
	ptr->value = var;
}

void printheight(node *ptr)
{

	//Performs post order traversal of tree rooted at ptr
	if (ptr != NULL)
	{
		printheight(ptr->left);
		printheight(ptr->right);
		if (ptr->parent)
		{
			printf("\n\nHeight of %d is %d and it's parent is %d", ptr->value, ptr->height, ptr->parent->value);
		}
		else
		{
			printf("\n\nThis is root %d and it's height is %d ", ptr->value, ptr->height);
		}
	}
}

static int findmax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

static int roottype(node *ptr)
{
	return findtype(ptr, 0);
}

static int nodetype(node *ptr)
{
	return findtype(ptr, 1);
}

static int findtype(node *ptr, int flag)
{
	/*Determines type of node. ex. leaf or internal*/
	if ((ptr->parent == NULL) && (flag))
	{
		return TYPEONE;
		//root
	}
	else if ((ptr->left == NULL) && (ptr->right == NULL))
	{
		return TYPETWO;
		//leaf node
	}
	else if (ptr->left == NULL)
	{
		return TYPETHREE;
		//internal node with right child
	}
	else if (ptr->right == NULL)
	{
		return TYPEFOUR;
		//internal node with left child
	}
	else
	{
		return TYPEFIVE;
		//internal node with left and right childs
	}

}

static int childtype(node *ptr)
{
	/*Determine wether ptr is left child of its parent or right child*/
	node *temp = ptr->parent;
	if (temp)
	{
		if (temp->left == ptr)
		{
			return LEFTCHILD;
		}
		else
		{
			return RIGHTCHILD;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	tree *obj = new_tree();
	for (int i = 0;i < 50;i++)
	{
		add(obj, i);
	}

	for (int i = 0;i < 40;i++)
	{
		rmroot(obj);
	}

	inorder(obj);
	postorder(obj);
	printheight(obj->root);

	searchvalue(obj, 91);
	return 0;
}

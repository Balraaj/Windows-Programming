#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct treenode node;

struct treenode
{
	int value;
	int height;
	node *left;
	node *right;
	node *parent;
};

node *root = NULL;
int childtype(node *);
bool isunbalanced(node *);
void rearrange(node*);
bool isheightchanged(node *);
void rm(node *);
int total = 0;

int max(int a, int b)
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

int nodetype(node *ptr,int flag=1)
{
	/*Determines type of node. ex. leaf or internal*/
	if ((ptr->parent == NULL)&&(flag))
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
	/*Determine wether ptr is left child of its parent or right child*/
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
}

node* parent(node *ptr)
{
	//Returns parent of "ptr"
	return ptr->parent;
}

node* leftchild(node *ptr)
{
	//Returns leftchild of "ptr"
	return ptr->left;
}

node* rightchild(node *ptr)
{
	//Returns right child of "ptr"
	return ptr->right;
}

node* createnode(int value)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->left = ptr->right = ptr->parent = NULL;
	ptr->value = value;
	ptr->height = 0;
	return ptr;
}

node* getposition(node *ptr, int value)
{
	/*Return address of the first node having value equal to "value", returns NULL if not found*/
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

int getheight(node *ptr)
{
	if (ptr == NULL)
	{
		return -1;
	}
	else
	{
		return ptr->height;

	}
}

int getotherchildheight(node *ptr)
{
	// returns height of sibling of ptr
	int var = childtype(ptr);
	if (var == 1)
	{
		return getheight(ptr->parent->right);
	}
	else
	{
		return getheight(ptr->parent->left);
	}
}

void setheight(node *start,node *stop=NULL)
{
	//sets height of nodes beggining from start to stop(excluding)
	while (start != stop)
	{
		start->height=max(getheight(start->right),getheight(start->left))+1;
		start = start->parent;
	}

}

int getbalfac(node *ptr)
{
	//Returns balance factor of a node
	return (-(getheight(ptr->left)) + (getheight(ptr->right)));
}

bool isleftheavy(node *ptr)
{
	if (getheight(ptr->left)>getheight(ptr->right))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isrightheavy(node *ptr)
{
	if (getheight(ptr->right)>getheight(ptr->left))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isunbalanced(node *ptr)
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

bool isheightchanged(node *ptr)
{
	int first = ptr->height;
	int second = max(getheight(ptr->left), getheight(ptr->right)) + 1;

	if (first == second)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void rotateright(node *ptr)
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
		root = new_root;
		new_root->parent = NULL;
	}
	else
	{
		int var = childtype(ptr);
		if (var == 1)
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

void rotateleft(node *ptr)
{
	node *new_root = ptr->right;
	ptr->right = new_root->left;

	if (ptr->right != NULL)
	{
		ptr->right->parent = ptr;
	}

	new_root->left = ptr;

	node *father = ptr->parent;
	if (father == NULL)
	{
		root = new_root;
		new_root->parent = NULL;
	}
	else
	{
		int var = childtype(ptr);
		if (var == 1)
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

void rearrange(node *ptr)
{
	if (isleftheavy(ptr))
	{
		if (isrightheavy(ptr->left))
		{
			ptr->left->right->height++;
			ptr->height -= 2;
			ptr->left->height--;
			rotateleft(ptr->left);
			rotateright(ptr);

		}
		else
		{
			ptr->height -= 2;
			rotateright(ptr);


		}
	}
	else if (isrightheavy(ptr))
	{
		if (isleftheavy(ptr->right))
		{
			ptr->right->left->height++;
			ptr->height -= 2;
			ptr->right->height--;
			rotateright(ptr->right);
			rotateleft(ptr);
		}
		else
		{
			ptr->height -= 2;
			rotateleft(ptr);

		}
	}
}

void balance(node *ptr)
{
	if (isheightchanged(ptr->parent))
	{
		while ((ptr)&&(!isunbalanced(ptr)))
		{
			setheight(ptr, ptr->parent);
			ptr = ptr->parent;
		}

		if (ptr)
		{
			setheight(ptr, ptr->parent);
			rearrange(ptr);
		}
	}
}

void add(node *ptr, int value)
{
	if (root == NULL)
	{
		node *temp = createnode(value);
		root = temp;
	}
	else
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

		balance(temp);
	}
}

void delntype1()
{
	int var = nodetype(root, 0);
	node *temp = NULL;
	switch (var)
	{
	case 2:
		// root is leaf
		free(root);
		root = NULL;
		break;
	case 3:
		//root has only right child
		temp = root->right;
		free(root);
		root = temp;
		break;

	case 4:
		//root has only left child
		temp = root->left;
		free(root);
		root = temp;
		break;
	case 5:
		//root has both childs
		if (root->left->right)
		{
			node *run = root->left->right;
			while (run->right)
			{
				run = run->right;
			}
			root->value = run->value;
			rm(run);
		}
		else if (root->right->left)
		{
			node *run = root->right->left;
			while (run->left)
			{
				run = run->left;
			}
			root->value = run->value;
			rm(run);
		}
		else
		{
			int var = getbalfac(root);
			temp = root;
			if (var == 1)
			{
				root = root->right;
				root->left = temp->left;
			}
			else if (var == -1)
			{
				root = root->left;
				root->right = temp->right;
			}
			else
			{
				root = root->left;
				root->right = temp->right;
				root->height++;
			}
			free(temp);
		}
		break;


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
	ptr->right->parent = temp;
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
	ptr->left->parent = temp;
	free(ptr);
}

void delntype5(node *ptr)
{
	//this function deletes an internal node having left and right childs
	node *temp = ptr->parent;
	node *start = NULL;
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

		run->left = branch;
		branch->parent = run;
		free(ptr);
		start = branch;
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
		branch->parent = run;
		free(ptr);
		start = branch;
	}
	setheight(start,temp);
}

void rm(node *ptr)
{
	/*Deletes node given by "ptr"*/
	int var = nodetype(ptr);
	node *temp = ptr->parent;

	switch (var)
	{
	case 1:
		delntype1();
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

	if (temp)
	{
		if (isheightchanged(temp))
		{
			setheight(temp);
		}
		while (temp)
		{
			if (isunbalanced(temp))
			{
				rearrange(temp);
				setheight(temp);
			}
			temp = temp->parent;
		}
	}
}

void inorder(node *ptr)
{
	/*Performs inorder traversal of tree*/
	if (ptr != NULL)
	{
		inorder(ptr->left);
		printf(" %d", ptr->value);
		inorder(ptr->right);
	}
}

void postorder(node *ptr)
{
	//Performs post order traversal of tree rooted at ptr
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf(" %d", ptr->value);
	}
}

void printheight(node *ptr)
{

	//Performs post order traversal of tree rooted at ptr
	if (ptr != NULL)
	{
		total++;
		printheight(ptr->left);
		printheight(ptr->right);
		if (ptr->parent)
		{
			printf("\n\nHeight of %d is %d and it's parent is %d", ptr->value, ptr->height,ptr->parent->value);
		}
		else
		{
			printf("\n\nThis is root %d and it's height is %d ", ptr->value,ptr->height);
		}
	}
}

int main()
{

	node obj;
	int arr[] = { 100,50,200,300,40,60,70,150,400,120,175,125,250,500};

	for (int i = 0;i < 14;i++)
	{
		add(root, arr[i]);
	}
	printf("\nInorder : \n");
	inorder(root);
	printf("\n\nPostorder : \n");
	postorder(root);


	printf("\n\n");
	printheight(root);


	rm(getposition(root, 40));
	rm(getposition(root, 500));
	printf("\nInorder : \n");
	inorder(root);
	printf("\n\nPostorder : \n");
	postorder(root);
	printf("\n\n");
	printheight(root);


	return 0;
}

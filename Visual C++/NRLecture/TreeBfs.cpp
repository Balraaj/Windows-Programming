#include<stdio.h>
#include<stdlib.h>


//Code for Tree and queue structure
typedef struct tree tree;
typedef tree *treeptr;
typedef struct node node;
typedef node *ptr;
treeptr root;
ptr start, end;

struct tree{
	int value;
	treeptr left;
	treeptr right;
};
struct node{
	treeptr value;
	ptr next;
};
void enqueue(treeptr x)
{
	ptr temp = (ptr)malloc(sizeof(node));
	temp->value = x;
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
		end = temp;
	}
	else
	{
		end->next = temp;
		end = temp;
	}
}
treeptr dequeue()
{
	if (start == NULL)
	{
		printf("\nQueue is empty\n");
		return NULL;
	}
	else
	{
		ptr temp = start;
		start = start->next;
		return temp->value;
		free(temp);
	}
}
treeptr newnode(int x)
{
	treeptr temp = (treeptr)malloc(sizeof(tree));
	temp->value = x;
	temp->left = temp->right = NULL;
	return temp;

}
void bfs(treeptr x)
{
	enqueue(x);
	if (x == NULL)
	{
		return;
	}
	
	else
	{
		while (start != NULL)
		{
			treeptr temp = dequeue();
			printf("\n%d", temp->value);
			if (temp->left != NULL)
				enqueue(temp->left);
			if (temp->right != NULL)
				enqueue(temp->right);
		}
	}
}
void insert(int data)
{
	if (root == NULL)
	{
		root = newnode(data);
	}

	else
	{
		
		treeptr run = root;
		treeptr prev;
		while (run!=NULL)
		{
			prev = run;

			if (data <= run->value)
				run = run->left;
			
			else 
			    run = run->right;
			
		}

		if (data<=prev->value)
		{
			prev->left = newnode(data);

		}
		else
		{
			prev->right = newnode(data);
		}
	}
}


int main()
{
	start =end= NULL;
	root = (treeptr)malloc(sizeof(tree));
	root->value = 20;
	root->left = root->right = NULL;
	for (int i = 1; i < 10; i++)
	{
		insert(i * 3);
	}
	insert(2);
	insert(1);
	insert(25);
	insert(10);
	insert(1);
	bfs(root);
	getchar();
	return 0;
}


	
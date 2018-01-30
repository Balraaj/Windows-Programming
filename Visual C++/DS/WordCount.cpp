#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node node;
struct node
{
	char *text;
	int count;
	node *left;
	node *right;
};

int getword(char *arr)
{
	char ch;
	while (isspace(ch = fgetc(stdin)))
	{
		printf("\nspace ignored");
	}
	if (ch == EOF)
	{	
		*arr = '\0';
		return EOF;
	}
	else
	{
		*(arr++) = ch;
		while ((ch = fgetc(stdin)) != ' '&&(ch!='\n'))
		{
			*(arr++) = ch;
		}
		*arr = '\0';
		return 0;
	}
}

char* wordalloc(char arr[])
{
	char *temp;
	int size = sizeof(arr) + 1;
	temp = (char*)malloc(size * sizeof(char));
	strcpy(temp, arr);
	return temp;
}

node* talloc(void)
{
	return (node*)malloc(sizeof(node));
}


node* addtree(node *ptr, char *arr)
{
	int cmp;
	if (ptr == NULL)
	{
		ptr = talloc();
		ptr->text = wordalloc(arr);
		ptr->left = ptr->right = NULL;
		ptr->count = 1;
	}
	else if ((cmp = strcmp(ptr->text, arr)) == 0)
	{
		ptr->count++;
	}
	else if (cmp < 0)
	{
		ptr->left = addtree(ptr->left, arr);
	}
	else
	{
		ptr->right = addtree(ptr->right, arr);
	}
	return ptr;
}

void tprint(node *ptr)
{
	if (ptr != NULL)
	{
		tprint(ptr->right);
		printf("%4d  %s\n", ptr->count, ptr->text);
		tprint(ptr->left);
	}
}

int main()
{
	node *root = NULL;
	char arr[100];

	while (getword(arr) != EOF)
	{
		if (isalpha(arr[0]))
		{
			root = addtree(root, arr);
		}
	}
	
	tprint(root);
	return 0;
}
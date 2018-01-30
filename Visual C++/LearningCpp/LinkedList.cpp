#include<iostream>
using namespace std;

class list
{
private:
	struct node {
		int value;
		node *ptr;
	};

	node *start, *end;
	int count;
public:
	list();
	void append(int);
	void print();
	void insert(int, int);
	int operator[](int);
};

int list::operator[](int index)
{
	if (index<0 || index>count)
	{
		cout << endl << "Index is out of bounds";
		return 0;
	}

	node *run = start;
	int temp = 0;
	while (temp != index)
	{
		run = run->ptr;
		temp++;
	}

	return run->value;
}

list::list()
{
	start = end = NULL;
	count = 0;
}


void list:: append(int x)
{
	node *temp;
	temp = new node;
	temp->value = x;
	temp->ptr = NULL;
	count++;

	if (start == NULL)
	{
		start = temp;
		end = temp;
    }

	else
	{
		end->ptr = temp;
		end = temp;
	}

}

void list::print()
{
	node *run = start;

	cout << endl<<"[";
	while (run->ptr != NULL)
	{
		cout << run->value<<",";
		run = run->ptr;
	}
	cout <<run->value<< "]"<<endl;
}

void list:: insert(int pos, int value)
{
	if (count==pos)
	{
		append(value);
	}

	else if (pos == 0)
	{
		node *temp = new node;
		temp->value = value;
		temp->ptr = start;
		start = temp;
	}

	else
	{
		int postemp=1;
		node *prev = start;
		node *next = start->ptr;
		while (postemp != pos)
		{
			postemp++;
			prev = next;
			next= next->ptr;
		}

		node *temp = new node;
		temp->value = value;
		temp -> ptr = next;
		prev->ptr = temp;


	}
}

void main()
{
	list mylist;
	
	for (int i = 0;i < 10;i++)
	{
		mylist.append(i);
	}

	mylist.insert(0,777);

	cout << mylist[0];
}
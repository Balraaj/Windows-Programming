#include<iostream>
#include<stdlib.h>
#include"Link.h"

using namespace std;

void showchoice()
{
	system("cls");
	cout << "    What you want to do : \n\n" << endl;
	cout << "    1. Add a new account" << endl;
	cout << "    2. find account info " << endl;
	cout << "    3. Show database " << endl;
	cout << "    4. Transfer money " << endl;
	cout << "    5. Add money " << endl;
	cout << "    6. Delete account " << endl;
	cout << "    7. Exit\n\n" << endl;
}
int getchoice()
{
	int ch;
	try {
		cout << "     Enter your choice : ";
		cin >> ch;

		cin.clear();
		cin.ignore(10000, '\n');

		if (ch != 1 && ch != 2 && ch != 3 && ch != 4&&ch!=5&&ch!=6&&ch!=7)
		{
			throw 1;
		}
	}

	catch (...)
	{
		system("cls");
		cout << "Please enter a valid choice";
		cin.clear();
		getchar();
	}

	return ch;
}
void processchoice(int x)
{
	switch (x)
	{
	case 1:
		system("cls");
		Link::getandinsert();

		break;

	case 2:
		system("cls");
		Link::findandshow();
		break;
	case 3:
		system("cls");
		Link::listdb();
		break;
	case 4:
		system("cls");
		Link::transfermoney();
		break;
	case 5:
		system("cls");
		Link::addmoney();
		break;
	case 6:
		system("cls");
		Link::getandremove();
		break;
	case 7:
		exit(0);
	}
}

int main()
{
	
	while (1)
	{
		
		showchoice();
		processchoice(getchoice());
	}
}
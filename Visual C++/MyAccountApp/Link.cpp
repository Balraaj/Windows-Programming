#include "Link.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#ifndef ACCOUNT_H
#include"Account.h"
#endif

using namespace std;

Account* Link::start = nullptr;
Account* Link::end = nullptr;

void Link::getandinsert()
{
	Link::insert(Account::create());
}

void Link::insert(Account *temp)
{
	if (start == nullptr)
	{
		start = end = temp;
	}
	else
	{
		end->next = temp;
		end = temp;
	}
}

Account* Link::find(int ac)
{

	Account *temp;
	temp = start;

		if (start == nullptr)
		{
			
			throw 101;
		}
	

	while ((temp->getac()) != ac)
	{
		temp = temp->next;
		if (temp == nullptr)
		{
			throw 99;
		}
	}
   
	return temp;
}

void Link::listdb()
{
	if (start == nullptr)
	{
		cout << "Database is empty" << endl;
		getchar();
		return;
	}

	Account *temp;
	temp = start;

	printf("%12s%12s%12s\n\n", "Name", "Account", "Balance");

	while (temp != nullptr)
	{
		Account::displayinfo(temp);
		temp = temp->next;
	}
	getchar();
}

void Link::findandshow()
{
	int ac;
	cout << "Enter account no : ";
	cin >> ac;
	system("cls");
	printf("%12s%12s%12s\n\n", "Name", "Account", "Balance");
	try {
		Account::displayinfo(Link::find(ac));
	}
	catch (int x)
	{
		if (x == 99)
			cout << "\tAccount no. doesn't exist";
		else
			cout << "\t\tDatabase is empty";
	}
	

	getchar();
	getchar();
}

void Link::transfermoney()
{
	int ac1, ac2, money;
	cout << "Here money will be transfered from account 1 to account 2\n\n";
	cout << "Enter account 1 : ";
	cin >> ac1;
	cout << "Enter account 2 : ";
	cin >> ac2;
	cout << "How much money you want to transfer : ";
	cin >> money;

	Account::transfer(ac1, ac2, money);
}

void Link::addmoney()
{
	int money, ac;
	cout << "Enter account no : ";
	cin >> ac;

	cout << "How much money to add : ";
	cin >> money;

	Account *temp = Link::find(ac);
	temp->addmon(money);
}

void Link::remove(int x)
{
	
    if ((start->getac()) == x)
	{
		start = start -> next;

	}
	else if ((end->getac()) == x)
	{
		Account *temp = start;
		while ((temp->next) != end)
		{
			temp = temp->next;
		}

		end = temp;
	}

	else
	{
		Account *prev = start;
		Account *temp=start->next;

		while ((temp->getac()) != x)
		{
			prev = temp;
			temp = temp->next;
		}

		prev->next = temp->next;
		free(temp);
	}
}

void Link::getandremove()
{
	int x;
	cout << "Enter account no : ";
	cin >> x;

	Link::remove(x);
}
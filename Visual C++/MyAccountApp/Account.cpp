#ifndef ACCOUNT_H
#include"Account.h"
#endif
#include<iostream>
#include<stdio.h>
#ifndef LINK_H
#include"Link.h"
#endif


using namespace std;

Account* Account::create()
{
	Account *temp;
	temp = new Account();

	cout << "Enter name : ";
	scanf("%s", (temp->name));
	cout << "Enter account no : ";
	cin >> temp->ac_no;
	cout << "Enter balance : ";
	cin >> temp->balance;
	

	return temp;
}

void Account::displayinfo(Account *temp)
{
	printf("%12s%12d%12d\n", temp->name, temp->ac_no, temp->balance);
}

int Account::getac()
{
	return ac_no;
}

void Account::transfer(int x, int y,int money)
{
	Account *a1 = Link::find(x);
	Account *a2 = Link::find(y);

	a1->balance = (a1->balance) - money;
	a2->balance = (a2->balance) + money;

	cout << "\n\noperation complete";
	getchar();
}

void Account::addmon(int x )
{
	balance = balance + x;
}

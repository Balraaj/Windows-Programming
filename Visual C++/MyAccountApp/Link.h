#pragma once
#include"Account.h"
class Link
{
private:
	static Account *start, *end;
	static void insert(Account*);
	static void remove(int x);
public:
	static void getandinsert();
	static void findandshow();
	static Account* find(int);
	static void transfermoney();
	static void listdb();
	static void addmoney();
	static void getandremove();
};


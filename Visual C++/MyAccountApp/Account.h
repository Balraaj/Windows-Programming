#pragma once
class Account
{
private:

	int ac_no;
	int balance;
	char name[20];

public:
	Account *next;
	int getac();
    static Account* create();
	static void displayinfo(Account*);
	static void transfer(int, int,int);
	void addmon(int);
};
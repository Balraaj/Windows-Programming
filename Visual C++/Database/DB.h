#pragma once
#include<iostream>
#include"mysql_connection.h"
using namespace std;
using namespace sql;
using namespace sql::mysql;
class DB
{
private:
	 string name;
	 int accout_no, balance;
	    
public:
	 void add(Connection*);
	 void del(Connection*);
	 void show(Connection*);
	 void transfer(Connection*);
     Connection* create();

};


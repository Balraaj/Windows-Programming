#include "DB.h"
#include <cppconn/prepared_statement.h>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include<iomanip>
Connection* DB::create()
{
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
	con->setSchema("AppDB");
	return con;
}

void DB::add(Connection* con)
{
	cout << "\n\tEnter customer details  ";
	cout << "\nEnter name : ";
	cin >> name;
	cout << "Enter account no : ";
	cin >> accout_no;
	cout << "Enter account balance : ";
	cin >> balance;

	sql::PreparedStatement *stmt;

	stmt = con->prepareStatement("INSERT INTO ac_table values(?,?,?)");
	stmt->setString(1, name);
	stmt->setInt(2, accout_no);
	stmt->setInt(3, balance);
    
	stmt->executeQuery();
}

void DB::del(Connection* con)
{
	int ac;
	cout << "\nEnter account no. to delete : ";
	cin >> ac;
	sql::PreparedStatement *stmt;
	sql::ResultSet *res;
	stmt = con->prepareStatement("SELECT cname FROM ac_table WHERE ac_no=?");
	stmt->setInt(1, ac);
	res = stmt->executeQuery();
	if (res->next())
	{
		stmt = con->prepareStatement("DELETE FROM ac_table WHERE ac_no=?");
		stmt->setInt(1, ac);
		stmt->executeQuery();
	}
	else
	{
		cout << "\nSorry , This account doesn't exist";
	}
}

void DB::show(Connection *con)
{
	sql::PreparedStatement *stmt;
	sql::ResultSet *res;

	stmt = con->prepareStatement("SELECT * FROM ac_table ORDER BY Cname ");
	res = stmt->executeQuery();

	cout << "\tName\t\t\tAccount\t\t  Balance\n\n";
	while (res->next())
	{
		cout << "\t"<<setw(10)<<left << res->getString("Cname") << "\t\t" <<left<< res->getInt("ac_no") << "\t\t" <<left<< res->getInt("balance")<<endl;
	}
}

void DB::transfer(Connection *con)
{
	int a, b,money;
	cout << "\nMoney will be transfered from Account A to Account B ";
	cout << "\nEnter Account A : ";
	cin >> a;
	cout << "\nEnter Account B : ";
	cin >> b;

	cout << "\n\nEnter amount : ";
	cin >> money;
	sql::PreparedStatement *stmt;
	stmt = con->prepareStatement("UPDATE ac_table SET balance=balance-? WHERE ac_no =?");
	stmt->setInt(1, money);
	stmt->setInt(2, a);
	stmt->executeQuery();

	stmt = con->prepareStatement("UPDATE ac_table SET balance=balance+? WHERE ac_no =?");
	stmt->setInt(1, money);
	stmt->setInt(2, b);
	stmt->executeQuery();
}
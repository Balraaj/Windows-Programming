#include"DB.h"
void menu();
int main()
{
	menu();
}

void menu()
{
	bool run = true;
	while (run)
	{
	system("cls");
	cout << "\nChoose your option ";
	cout << "\n1. To create new account";
	cout << "\n2. To delete an account ";
	cout << "\n3. For list of all accounts";
	cout << "\n4. To transfer money";
	cout << "\n5. To exit";
	cout << "\n\nEnter your choice : ";
	int choice=0;
	cin >> choice;
	cin.clear();
	

	DB obj;

	
		switch (choice)
		{
		case 1:
			system("cls");
			obj.add(obj.create());
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			obj.del(obj.create());
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			obj.show(obj.create());
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			obj.transfer(obj.create());
			getchar();
			getchar();
			break;
		case 5:
			run = false;
			break;
		}
	}
}
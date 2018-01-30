#include<iostream>
#include<fstream>
using namespace std;

class student
{
public:
	char name[20];
	int roll;

	student() = default;
	student(char *n, int r)
	{
		strcpy(name, n);
		roll = r;
	}

	void show()
	{
		cout << "\nName is : " << name;
		cout << "\nRoll is : " << roll;
	}
};

void main()
{
	student arr[5];
	ofstream out("myfile");
	for (int i = 0;i < 5;i++)
	{
		cout << "Enter details of student " << i + 1;
		cout << "\nEnter name : ";
		cin >> arr[i].name;
		cout << "\nEnter Roll : ";
		cin >> arr[i].roll;
		out.write((char*)&arr[i], sizeof(student));
	}
}
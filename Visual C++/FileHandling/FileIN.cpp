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
		cout << "\n\nName is : " << name;
		cout << "\nRoll is : " << roll;
	}
};

void main()
{
	ifstream in("myfile");
	student arr[5];

	for (int i = 0;i < 5;i++)
	{
		in.read((char*)&arr[i], sizeof(student));
		arr[i].show();
	}

	
}
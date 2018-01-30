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

ofstream& operator<<(ofstream& out, student& obj)
{
	out.write((char*)&obj, sizeof(student));
	return out;
}

ifstream& operator>> (ifstream& in, student& obj)
{
	in.read((char*)&obj, sizeof(student));
	return in;
}

void main()
{
	student obj1("Balraj", 1);
	student obj2("Rajaram", 2);

	ofstream out("myfile");
	out << obj1<<obj2;

	out.close();
	student arr[2];

	ifstream in("myfile");
	for (int i = 0;i < 2;i++)
	{
		in.read((char*)&arr[i], sizeof(student));
		cout << "\n\nDetails";
		arr[i].show();
	}

}
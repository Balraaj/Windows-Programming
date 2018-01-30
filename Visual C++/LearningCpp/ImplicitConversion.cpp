/* This program shows the use of explicit keyword with the constructors. explicit keyword is used to stop the implicit conversion.
   in this program if we didn't had single parameter constructor than this code wouldn't had worked*/

#include<iostream>
using namespace std;

class temp
{
private: 
	int value;
public:
    temp(int);
	void disp();
};

temp::temp(int x) :value{ x }
{
	cout << "\nConstructor is called";
}

void temp::disp()
{
	cout << "\nValue is : " << value;
}
void disp(temp obj)
{
	obj.disp();
}

void main()
{
	temp t1{ 100 };
	t1.disp();

	disp(777); // Implicit conversion from int to temp using singal parameter constructor
}
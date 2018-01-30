/* This program shows that default arguments can only be defined once , either in the declaration or definition of constructor*/
#include<iostream>
using namespace std;

class temp
{
private:
	int value;
public:
	temp(int x=100);
	void disp();
};

temp::temp(int x = 100) :value{ x }
{
	cout << "\nConstructor is called";
}

void temp::disp()
{
	cout << "\nValue is : " << value;
}

void main()
{
	temp t1;
	t1.disp();
	temp t2(900);
	t2.disp();
}
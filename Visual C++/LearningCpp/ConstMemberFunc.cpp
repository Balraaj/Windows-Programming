/* This program shows how we can use const qualifier on a member function , once declared const the member function can not modify 
   the data members of object*/
#include<iostream>
using namespace std;

class temp
{
private:
	int value;
public:
	temp();
	temp(int);
	void disp() const;
};

temp::temp() :value{ 1 }
{}

temp::temp(int x):value{x}
{}

void temp::disp() const
{
	cout << "\nValue is : " << value;


}

void main()
{
	temp t1;
	t1 = 90; //implicit conversion 
	t1.disp();
}
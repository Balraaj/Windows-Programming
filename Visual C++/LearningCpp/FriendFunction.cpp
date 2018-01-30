/* This program shows working of argument dependant lookup , as we have defined a friend function
   inside the class, when we call it compiler gives the error that symbol is not found but when we call it using temp () argument
   the function works fine. we should declare it in global scope in order to make it work in all condtions*/
#include<iostream>
using namespace std;

class temp
{
private:
	int value;
public:
	temp();
	temp(int);
	friend void  disp(temp obj) 
	{
		cout << "\nValue is : " << obj.value;
	}
};

temp::temp()
{
	value = 0;
}

temp::temp(int x) :value{ x }
{

}

void main()
{
	
	disp(temp()); // argument dependant lookup

}
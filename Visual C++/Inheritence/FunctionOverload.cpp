/*This program shows that even if base class has any function with same name as any function in derived class, object of derived will always call the 
  function of derived class and not of base class and if they have different argument list they will not be overridden. if we want to overload them
  then we can use 
                  using base::funcionname;
				                           in the derived class, it declares the function in derived class and not the overloaded can be done*/
#include<iostream>
using namespace std;

class base
{
private:
	int value;
public:
	base(int);
	void display(); //function with same name as derived class function
	void callme();
};

base::base(int x) :value{ x }
{};

void base::display()
{
	cout << "\nBase display called\nBase Value is : " << value;
}

void base::callme()
{
	cout << "\nYou called me";
}

class derived :public base
{
private:
	int d_value;
public:
	using base::display; //delaring the base class function in derived class for the purpose of overloading
	derived(int, int);
	void display(); //function with same name as base class function 
};

derived::derived(int x,int y):base(x),d_value{y}
{};

void derived::display()
{
	
	cout << "\nDerived value is : " << d_value;
}

void main()
{
	derived d(10, 20);
	d.display();
	d.callme();
}

/* In this case even if we declared base display function in derived class but still when we call it using derived object , the derived display function
   will be called , its because both are identical in argument list , overloading will only occur if they had different argument list. you can try it by 
   changing argument list of one function ( base or derived) */
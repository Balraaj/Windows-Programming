#include<iostream>
using namespace std;

class temp
{
private: 
	int pr_value;
public:
	int pub_value;
	temp();
	temp(int, int);
	void disp();
};

temp::temp():pr_value{1},pub_value{1}
{
	cout << "\nBase default constructor";
}

temp::temp(int x,int y): pr_value{x},pub_value{y}
{
	cout << "\nBase parametrized constructor";
}

void temp::disp()
{
	cout << "\nPrivate value is : " << pr_value << "\nPublic value is : " << pub_value;
}

class derived : temp
{
private:
	int der_pr_value;
public:
	int der_pub_value;
	derived();
	derived(int, int, int, int);
	void der_disp();
};

derived::derived():der_pr_value{1},der_pub_value{1},temp()
{
	cout << "\nDerived default constructor";
}

derived::derived(int w,int x,int y,int z):der_pr_value{w},der_pub_value{x},temp(y,z)
{
	cout << "\nDerived parametrized constructor";
}

void derived::der_disp()
{
	
	cout << "\nPrivate of derived : " << der_pr_value;
	cout << "\nPublic of derived : " << der_pub_value;
	disp();
}


void main()
{
	cout << "\nCreating D1";
	derived d1;
	cout << "\nCreating D2";
	derived d2(1, 2, 3, 4);
	cout << "\n\nD1 calls the display\n\n";
	d1.der_disp();
	cout << "\n\nD2 calls the display\n\n";
	d2.der_disp();

}
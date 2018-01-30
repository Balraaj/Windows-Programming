#include<iostream>
using namespace std;

class temp
{
private:
	int h, w;
public:
	temp();
	temp(int);
	temp(int, int);
	void disp();
};

temp::temp() :h{ 0 }, w{ 0 }
{};

temp::temp(int x, int y) :h{ x }, w{ y }
{};

temp::temp(int x) :temp(x, x)
{};

void temp::disp()
{
	cout << "\nHeight : " << h<<endl<<"Weight : "<<w;
}

void main()
{
	temp t1;
	temp t2(50, 100);
	temp t3(900);
	t1.disp();
	t2.disp();
	t3.disp();
}
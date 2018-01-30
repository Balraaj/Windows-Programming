#include<iostream>
using namespace std;

class A
{
private:
	int A_value;
public:
	A(int);
	void Ashow();
	//A()=default;
};

A::A(int x):A_value{x}
{};

void A::Ashow()
{
	cout << "\nA_value is " << A_value;
}

class B :virtual public A
{
private:
	int B_value;
public:
	B(int, int);
	void Bshow();
};

B::B(int x,int y):A(x),B_value{y}
{};

void B::Bshow()
{
	cout << "\nB_Value is " << B_value;
}

class C :virtual public A
{
private:
	int C_value;
public:
	C(int, int);
	void Cshow();
};

C::C(int x,int y):A(x),C_value{y}
{};

void C::Cshow()
{
	cout << "\nC_Value is " << C_value;
}

class D :public B, public C
{
private:
	int D_value;
public:
	D(int, int, int);
	void Dshow();
};

D::D(int w,int x,int y):B(w,x),C(w,x),D_value{y}
{};

void D::Dshow()
{
	cout << "\nD_value is " << D_value;
}


int main()
{
	D d1(10, 20, 30);
	d1.Ashow();
	return 0;
}

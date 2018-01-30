#include<iostream>
using namespace std;

class base
{
private:
	int b_private;
protected:
	int b_protected;
public:
	base(int, int);
	void display();
};

base::base(int x, int y) :b_private{ x }, b_protected{ y }
{};

void base::display()
{
	cout << "Private value : " << b_private;
	cout << "\nProtected value : " << b_protected;
}

class derived :private base
{
private:
	int d_private;
protected:
	int d_protected;
public:
	derived(int, int, int, int);
	void display();
};

derived::derived(int w,int x,int y,int z):base(w,x),d_private{y},d_protected{z}
{};

void derived:: display()
{
	cout << "\nDerived private value : " << d_private;
	cout << "\nDerived protected value : " << d_protected;
	cout << "\nBase protected value : " << b_protected;
}

class grandchild :private derived
{
public:
	grandchild::grandchild(int w, int x, int y, int z) :derived(w, x, y, z)
	{};

	void display()
	{
		cout<<"\n"<<d_protected
	}
};
int main()
{

	derived d(10, 20, 30, 40);
	d.display();
}
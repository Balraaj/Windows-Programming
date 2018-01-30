#include<iostream>
#include<math.h>
using namespace std;

void coff(int model, double &a, double &b, double &c, double &d)
{
	switch (model)
	{
	case 1:
		a = 2.4;
		b = 1.05;
		c = 2.5;
		d = 0.38;
		break;
	case 2:
		a = 3.0;
		b = 1.12;
		c = 2.5;
		d = 0.35;
		break;
	case 3:
		a = 3.6;
		b = 1.20;
		c = 2.5;
		d = 0.32;
		break;
	}
}

void cal(double &a, double &b, double &c, double &d, double &size)
{
	double effort, time, staff, productivity;
	effort = a*pow(size, b);
	time = c*pow(size, d);
	staff = effort / time;
	productivity = size / effort;

	cout << "\nEffort applied : " << effort;
	cout << "\nTime required  : " << time;
	cout << "\nStaff required : " << staff;
	cout << "\nproductivity   : " << productivity;
}

void main()
{
	int model;
	cout << "Choose the model \n";
	cout << "1: Organic\n";
	cout << "2: Semi-detached\n";
	cout << "3: Embedded\n";
	cout << "\nEnter choice : ";


	cin >> model;

		double size;
	cout << "\nEnter size in KLOC : ";
	cin >> size;

	double a, b, c, d;
	a = b = c = d = 0;

	coff(model, a, b, c, d);
	cal(a, b, c, d,size);

}
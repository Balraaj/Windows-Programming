#include<iostream>
using namespace std;

template <class T,class U>

T add(T v1, U v2)
{
	return v1 + v2;
}

template <class T,class U>
T sub(T v1, U v2)
{
	return v1 - v2;
}

template <class T,class U>
T mul(T v1, U v2)
{
	return v1*v2;
}

void main()
{
	cout << "1: Addtion\n2: Subtraction\n3: Multiplication\n\nEnter your choice :	";
	double result, v1;
	int ch;
	int v2;
	cin >> ch;
	cout << "\nEnter value 1 : ";
	cin >> v1;
	cout << "\nEnter value 2 : ";
	cin >> v2;

	switch (ch)
	{
	case 1:
		result = add(v1, v2);
		break;
	case 2:
		result = sub(v1, v2);
		break;
	case 3:
		result = mul(v1, v2);
		break;

	}

	cout << "\nResult is : " << result;
}
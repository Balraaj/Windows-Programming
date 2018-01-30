/*This program checks two consecutive words if they are same, to stop press ctrl+z and then enter*/
#include<iostream>
#include<string>
using namespace std;

void main()
{
	string previos = " ";
	string current;
	
	while (cin>>current)
	{
		if (current == previos)
		{
			cout << "\nThis is same word";
		}
		previos = current;
	}
}
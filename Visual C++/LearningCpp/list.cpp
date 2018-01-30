/*This program shows how to use lists to store data , it also shows use of iterators*/
#include<iostream>
#include<list>

using namespace std;

int main()
{
	list <int> *mylists;

	mylists = new list<int>[10];

	for (int k = 0;k < 10;k++)
	{
		for (int i = 0;i < 10;i++)
		{
			mylists[k].push_back(i);
		}
	}

	list<int>::iterator ptr;
	for (int k = 0;k < 10;k++)
	{
		cout << "\n\nValues in list " << k;
		ptr = mylists[k].begin();
		for (int i = 0;i < 10;i++)
		{

			cout << endl << *ptr++;
		}
	}
	

}
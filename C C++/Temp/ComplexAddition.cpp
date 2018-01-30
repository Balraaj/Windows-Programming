//This program overloads + operator to add two complex no.

#include<iostream>
#include<stdlib.h>
using namespace std;

class comp
{
private:
    int real,imagine;
    static char i;

public:
    void getno();
    void showno();

    comp operator+(comp);
};

char comp::i='i';

void comp::getno()
{
    system("cls");
    cout<<"\nEnter real part : ";
    cin>>real;
    cout<<"\nEnter imaginary part : ";
    cin>>imagine;
}

void comp::showno()
{
    system("cls");
    cout<<endl<<"No. is : "<<real<<" + "<<imagine<<i;
}

comp comp::operator+(comp obj)
{
    comp temp;
    temp.real=real+obj.real;
    temp.imagine=imagine+obj.imagine;

    return temp;
}

int main()
{
    comp a,b;
    a.getno();
    b.getno();

    comp c= a+b;

    c.showno();

}


















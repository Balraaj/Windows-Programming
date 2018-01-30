/*This program show difference in copy constructor and assignment operator and it uses implicitly
  versions of them */

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class temp
{
  private:
      int roll;
      char name[20];
  public:
      void getinfo();
    void showinfo();

};

void temp::getinfo()
{
    system("cls");
    cout<<"Enter Name : ";
    scanf("%s",name);
    cout<<"\nEnter roll no. : ";
    cin>>roll;
}

void temp::showinfo()
{
    cout<<"\nName is : "<<name<<endl<<"Roll no is : "<<roll;

}




int main()
{
  temp a;
  a.getinfo();
  temp b=a; //calls copy constructor
  temp c;
  c=b; //calls copy assignment operator
 cout<<"\nA is calling it";
  a.showinfo();
  cout<<"\n\nB is calling it";
  b.showinfo();
  cout<<"\n\nC is calling it";
  c.showinfo();

}

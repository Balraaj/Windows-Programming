/* This program shows use of copy constructor and copy assignment operator and uses explicitly defined
   versions of them , it also explains how a copy constructor is called when an object is passed by
   value to a function */

   #include<iostream>
   #include<stdlib.h>
   #include<stdio.h>

   using namespace std;

   class temp
   {
   private:
    int roll;
    string name;
   public:
    temp ()=default;
    temp(temp &);
    void getinfo();
    static void showinfo(temp);
   };

temp::temp(temp &obj)
{
    cout<<"\nCopy constructor called\n";
    roll=obj.roll;
    name=obj.name;
}

void temp::getinfo()
{
    cout<<"\nEnter name : ";
    cin>>name;
    cout<<"\nEnter roll no : ";
    cin>>roll;
    system("cls");
}

void temp::showinfo(temp z)
{
    cout<<"\nName : "<<z.name<<endl<<"Roll : "<<z.roll;
}

int main()
{
    temp a;
    a.getinfo();
    temp d;
    d=a; //Calls copy assignment
    temp::showinfo(a); // Calls copy constructor

}

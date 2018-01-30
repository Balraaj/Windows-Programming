/* This program shows the use of copy constructor and assignment operator , in this program copy constructor
   gets called twice ,once for the object creation in main and another time is when assignment operator is
   called and object is passed by value. if we pass the object by reference to assignment operator then we can
   copy constructor is called only once */
#include<iostream>
using namespace std;

class temp
{
private:
    int value;
public:
    temp(int);
    temp(temp&);
    void disp();
    temp operator=(temp);
};

temp::temp(int x)
{
    value=x;
}

temp::temp(temp obj)
{
    cout<<"\nCopy constructor called";
    value=obj.value;
}

temp temp::operator=(temp &obj)
{
    cout<<"\nAssingment operator is called";
    temp obj1(0);
    obj1.value=value=obj.value;
}

void temp::disp()
{
    cout<<"\nValue is : "<<value;
}

int main()
{
    temp t1(100);
    temp t2(t1);
    temp t3(900);
    t3=t1;
    t1.disp();
    t2.disp();
}



















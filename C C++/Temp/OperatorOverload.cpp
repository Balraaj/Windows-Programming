//This program shows the concept of operator overloading
#include<iostream>

using namespace std;

class MyClass
{
private:
    int value;
public:
    MyClass();
    void setvalue();
    void getvalue();
    MyClass operator+(MyClass);

};

MyClass::MyClass()
{
    value=100;
}

MyClass MyClass::operator+(MyClass obj)
{
    MyClass temp;
    temp.value=value+obj.value;

    return temp;
}

void MyClass::setvalue()
{
    cout<<"Enter value : ";
    cin>>value;
}

void MyClass::getvalue()
{
    cout<<"\nValue is : "<<value;
}

int main()
{
    MyClass obj1;
    MyClass obj2;
    MyClass obj3=obj1+obj2;
    MyClass obj4=obj1+obj2+obj3;

    obj1.getvalue();
    obj2.getvalue();
    obj3.getvalue();
    obj4.getvalue();
}

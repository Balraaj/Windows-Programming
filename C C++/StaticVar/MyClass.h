#ifndef MYCLASS_H
#define MYCLASS_H

#include<iostream>
using namespace std;

class MyClass
{
    public:

        static int value;
        void inc();
        void show();


};

int MyClass::value;

void MyClass::inc()
{
    value++;
}

void MyClass::show()
{

    cout<<endl<<value;
}

#endif // MYCLASS_H

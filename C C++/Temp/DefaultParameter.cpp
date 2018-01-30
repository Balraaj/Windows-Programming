/* This program overloads new and delete operators */
#include<iostream>
#include<stdlib.h>
using namespace std;

class temp
{
private:
    int value;
public:
    temp(int);
    void showvalue();
    void* operator new(size_t );
    void operator delete(void *);
};

temp::temp(int z=10)
{
    value=z;
}

void temp::showvalue()
{
    cout<<"\nValue : "<<value;
}

void* temp:: operator new(size_t n)
{
    cout<<"\nOverloaded new is called ";
    void *p=malloc(n);
    return p;
}

void temp::operator delete(void *p)
{
    cout<<"\nOverloaded delete is called";
    free(p) ;
}


int main()
{
    temp *p=new temp;
    p->showvalue();
    delete p;
}

#include "SuperBase.h"
#include<iostream>
using namespace std;

void SuperBase::setvalue(int x)
{
    try
    {
        if(x==0)
        {
            throw 1;
        }
        value=x;
    }
    catch(double z)
    {


    }
}

void SuperBase::func(int z)
{

    try
    {
        setvalue(z);

    }
    catch(...)
    {
        cout<<"Exception is caught";
    }
}

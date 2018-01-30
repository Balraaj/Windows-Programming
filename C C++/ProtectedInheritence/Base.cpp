#include "Base.h"
#include<iostream>
using namespace std;

void Base::setvalues(int a,int b,int c)
{
    pub_x=a;
    prot_y=b;
    priv_z=c;
}

void Base::show()
{
    cout<<pub_x<<endl<<prot_y<<endl<<priv_z<<endl;
}

#include <iostream>
#include "Base.h"
#include "Derived.h"
using namespace std;

int main()
{
    Base b1;
    b1.setvalues(1,2,3);
    b1.show();
    Derived d1;
    d1.setvalues(10,11,12);
    d1.show();
}

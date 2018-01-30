//This program shows that protected members cant be accessed in main

#include <iostream>
#include "MyClass.h"
using namespace std;

int main()
{
 MyClass obj;
 obj.x;
 obj.y;
 obj.z;
}

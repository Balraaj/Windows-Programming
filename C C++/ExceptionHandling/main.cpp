/* This program shows how exception handling works , if a function which throws the exception does not
  catch it then exception will fall back to the calling function until it finds a suitable handler */

#include <iostream>
#include "SuperBase.h"
using namespace std;

int main()
{
    SuperBase b1;
    b1.func(0);
}

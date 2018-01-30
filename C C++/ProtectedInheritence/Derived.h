#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"


/*you can change public access specifier to protected or private and this code wont work because when we inherit
  a class using protected specifier , all the public and protected members of base class become protected members
  derived ,which means we can only access them from a member of derived and not from main*/


class Derived: public Base{
    public:
        int der_x;
};

#endif

/*This program shows how to pass parameters to base class constructor and it also show how to use
  explicit keyword*/

#include<iostream>

using namespace std;

class base
{
private:
    int base_value;
public:
    base(int x)
    {
        base_value=x;
    }

    base ()=default;
};

class derived:public base
{
private:
    int derived_value;
public:
    explicit derived(int x):base(x)
    {
        derived_value=x;
    }
    void get_value()
    {
        cout<<"Value is : "<<derived_value;
    }

};

int main()
{
    derived d1(10);
    d1.get_value();
}

#include <iostream>

using namespace std;

int func1(int x,int y)
{
    return x+y;
}

int func2(int x,int y)
{
    return x-y;
}
typedef int (*ptr)(int,int);

ptr choose(char z)
{
    if(z=='a')
        return func1;
    else
        return func2;
}


int main()
{
    char c;
    cout<<"Press a to sum "<<endl;
    cout<<"Press b to subtract"<<endl;

    cin>>c;
    ptr z =choose(c);

    cout<<"Sum is = "<<z(100,28);
    return 0;
}

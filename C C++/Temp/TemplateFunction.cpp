#include <iostream>

using namespace std;
template <class T>
void swapit(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    int x,y;
    cout<<"Enter two integers to swap:\n\n";
    cout<<"X : ";
    cin>>x;
    cout<<"Y : ";
    cin>>y;

    swapit(x,y);

    cout<<"\n\nAfter swapping :\n\n";
    cout<<"X : "<<x<<"\nY : "<<y;

    char a,b;
    cout<<"\n\nEnter two chars to swap:\n\n";
    cout<<"X : ";
    cin>>a;
    cout<<"Y : ";
    cin>>b;

    swapit(a,b);
    cout<<"\nAfter swapping :\n\n";
    cout<<"X : "<<a<<"\nY : "<<b;


}

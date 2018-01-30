//This program shows some basic io formatting in cpp
#include<iostream>
#include<iomanip>
using namespace std;

 int main()
 {
     int value;
     cout<<"Enter value : ";
     cin>>value;

     cout<<"\nValue : "<<hex<<uppercase<<value;

     double value1;

     cout<<"\n\nEnter double value : ";
     cin>>value1;

     cout<<"\nValue : "<<setw(10)<<setfill('0')<<value1;
     return 0;
 }

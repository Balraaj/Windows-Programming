/*This program uses an object of class ifstream to read integers from a disk file created by temp.exe
  using read function.*/
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream in("temp.txt",ios::binary|ios::in);
    int i=0;

    while(i<10)
    {
        int value;
        in.read((char*)&value,sizeof(int));

        cout<<"\nValue is : "<<value;
        i++;
    }
    return 0;
}

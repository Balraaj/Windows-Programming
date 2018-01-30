/*This program writes to a disk file using write function */
#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    ofstream out("temp.txt",ios::binary|ios::out);


    int i=0;
    while(i<10)
    {
        int value;
        cout<<"Enter value : ";
        cin>>value;

        out.write((char*)&value,sizeof(int));
        i++;
    }
}

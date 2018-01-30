//This program uses Cpp IO to store values in a disk file and then retrieve these values.
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   ofstream out("Filehandlingcpp.txt",ios::binary|ios::out);

   int no;
   int i=0;
   while(i<10)
   {
       cout<<"Enter no : ";
       cin>>no;
       out.write((char *)&no,sizeof(int));
       i++;
   }


   out.close();

   cout<<"\n\nReading from file : \n\n";

   ifstream in("Filehandlingcpp.txt",ios::binary|ios::in);

   i=0;
   while(i<10)
   {
       in.read((char*)&no,sizeof(int));
       cout<<endl<<"No is : "<<no;
       i++;
   }

   in.close();
   return 0;
}

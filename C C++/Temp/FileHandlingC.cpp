//This program shows use of c file IO , fwrite and fread to be specific
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    FILE *fp;
    int sum=0,avg;
    int arr[10];

    fp=fopen("Numbers.txt","w");

    if(fp==nullptr)
    {
        cout<<"Error ";
        return 1;
    }

    cout<<"Enter numbers to calculate average : \n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"Enter no : ";
        cin>>arr[i];
    }

    fwrite(arr,sizeof(int),10,fp);
    fclose(fp);

    fp=fopen("Numbers.txt","r");
    if(fp==nullptr)
    {
        cout<<"Error";
        return 1;
    }

    fread(arr,sizeof(int),10,fp);

    for(int i=0;i<10;i++)
    {
        sum+=arr[i];
    }

    avg=sum/10;

    cout<<"\nAvg is : "<<avg;
    return 0;
}

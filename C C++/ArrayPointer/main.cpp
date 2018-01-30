//This program initializes array using pointer arithmetic.

#include <iostream>

using namespace std;

int main()
{

    int arr[3][3];
    int *ptr=&arr[0][0];

    int n=1;

    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            *(ptr+(i*3)+j)=n++;
        }
    }

    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            cout<<"\t"<<arr[i][j];
        }
    cout<<endl;

    }
    return 0;
}

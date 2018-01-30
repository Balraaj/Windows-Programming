#include <iostream>

using namespace std;

class Myclass
{
public :
    int z;
    static int x;
    static void inc()
    {
        //This function can not access z as it is static function
        x++;
    }

    void show()
    {

        cout<<"\n\nValue of x = "<<x;
        cout<<"\nValue of z = "<<z;
    }
};

int Myclass::x=9;
int main()
{
    Myclass a;
    a.inc();
    a.show();

    Myclass b;
    b.inc();
    b.show();

    return 0;
}

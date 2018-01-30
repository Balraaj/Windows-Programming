package Temp;
class A
{
   synchronized public void show(int x,String str)
    {
        try
        {
            System.out.print("["+str);
            if((x==1)||(x==3))
            {
                Thread.currentThread().wait();
            }
            if(x==2)
            {
                Thread.currentThread().notify();
            }
        }
        catch(InterruptedException e)
        {

        }

        System.out.print("]");
    }
}

class MyThread extends Thread
{
    int no;
    String str;
    A obj;
    Thread t;
    MyThread(A a, int n, String s)
    {
        no = n;
        obj = a;
        str = s;
        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        obj.show(no,str);
    }
}

public class Demo
{
    public static void main(String[] args)
    {
        A a = new A();
        MyThread obj1 = new MyThread(a,1,"Balraj");
        MyThread obj2 = new MyThread(a,2,"Singh");

        MyThread obj3 = new MyThread(a,3,"Brar");
    }
}
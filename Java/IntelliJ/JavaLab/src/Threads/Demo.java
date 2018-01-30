package Threads;

class MyThread extends Thread
{
    int time,no;
    Thread t;

    MyThread(int x,int y)
    {
        no = x;
        time = y;

        System.out.println("\nThread "+x+" is starting : :");
        start();
    }

    public void run()
    {
        try
        {
            for(int i =0;i<10;i++)
            {
                System.out.print("\nThread "+no+" writes : "+i);
                sleep(time);
            }
        }
        catch(InterruptedException e)
        {
            System.out.print("\nCaught exception");
        }
    }
}


public class Demo
{
    public static void main(String[] args)
    {
        MyThread a = new MyThread(1,1000);
        MyThread b = new MyThread(2,5000);
    }
}
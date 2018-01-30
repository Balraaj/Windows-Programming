package Thread;

/**
 * Created by Balraj on 15-06-2016 and edited on github.
 */
public class MyThread implements Runnable
{
    Thread t;

    MyThread(String name)
    {
        t=new Thread(this,name);
        System.out.println("My Thread is starting : ");
        t.start();
    }

    public void run()
    {
        try {
            for (int i = 0; i < 100; i++) {
                System.out.println("My thread : " + i);
                t.sleep(1000);

                if(i>10)
                {
                    t.setPriority(10);
                }
            }
        }

        catch(InterruptedException E)
        {
            System.out.println("Thread is intrupted");
        }

        System.out.println("My thread is exiting");
    }

}


class myclass {
    public static void main(String args[])
    {
        MyThread T =new MyThread("Balraj");

        Thread obj=Thread.currentThread();

        try
        {
            for(int i=0;i<100;i++)
            {
                System.out.println("Main thread : "+i);
                obj.sleep(1000);
                if(i>10)
                {
                    obj.setPriority(1);
                }
            }
        }
        catch(InterruptedException E)
        {
            System.out.println("Main thread is intruppted");
        }
    }
}

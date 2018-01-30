package ThreadSync;

class call
{
    public void show(String msg)
    {
        try
        {
            System.out.print("["+msg);
            Thread.sleep(2000);
        }
        catch (InterruptedException e)
        {
            System.out.print("Caught it");
        }

        System.out.print("]");
    }
}

class Sync extends Thread
{
    call obj;
    String msg;
    Thread t;
    Sync(call a,String s)
    {
        obj = a;
        msg = s;
        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        synchronized (obj)
        {
            obj.show(msg);
        }
    }
}


public class Demo
{
    public static void main(String[] args)
    {
        call obj = new call();
        Sync a = new Sync(obj,"Balraj");
        Sync b = new Sync(obj,"Singh");
        Sync c = new Sync(obj,"Brar");
    }
}

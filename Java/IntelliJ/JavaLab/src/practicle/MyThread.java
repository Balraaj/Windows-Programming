package practicle;

public class MyThread extends Thread
{
    Thread t;
    int time;
    String name;

    MyThread(int time,String name)
    {
        this.t = new Thread(this);
        this.time = time;
        this.name = name;

        System.out.print("Thread "+this.name+" started \n");
        t.start();
    }

    public void run()
    {
        paint(this.name);
    }

  synchronized static void paint(String str)
    {
        System.out.print("[ "+str);

        try
        {
            Thread.sleep(3000);
        }
        catch(InterruptedException e)
        {

        }

        System.out.print(" ]");
    }

}

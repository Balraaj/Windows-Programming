package practicle;

public class Consumer  extends Thread
{
    Q q;

    Consumer(Q q)
    {
        this.q = q;
        new Thread(this).start();
    }

    public void run()
    {
        while(true)
        {
            q.get();
        }
    }
}

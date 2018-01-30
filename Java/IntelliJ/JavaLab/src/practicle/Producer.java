package practicle;

public class Producer extends Thread
{
    Q q;

    Producer(Q q)
    {
        this.q = q;
        new Thread(this).start();
    }

    public void run()
    {
        int i = 0;

        while(i<10)
        {
          q.put(i++);
        }
    }
}

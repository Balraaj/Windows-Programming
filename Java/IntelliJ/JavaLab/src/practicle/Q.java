package practicle;

public class Q
{
    static int n;
    static boolean flag  = false;

    synchronized void put(int x)
    {
        while(flag)
        {
            try
            {
                this.wait();
            }
            catch (InterruptedException e)
            {

            }

        }
        this.n = x;
        System.out.println("Put : " + this.n);
        flag = true;
        notify();
    }

    synchronized void get()
    {
        while(!flag)
        {
            try
            {
                this.wait();
            }
            catch(InterruptedException e)
            {

            }

        }


        System.out.println("Got : "+this.n);
        flag = false;
        notify();


    }
}

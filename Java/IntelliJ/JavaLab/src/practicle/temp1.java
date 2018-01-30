package practicle;

public class temp1
{
    public static void main(String[] args)
    {
        Q q = new Q();
        Producer p = new Producer(q);
        Consumer c = new Consumer(q);


    }
}

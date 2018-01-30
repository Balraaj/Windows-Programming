/*
This is iterative version of the same algorithm
 */
public class FibonacciIterative
{
    private static int fib(int n)
    {
        int next=0;
        int back2=0,back1=1;

        for(int i=2;i<=n;i++)
        {
            next=back1+back2;
            back2=back1;
            back1=next;
        }
        return next;
    }

    public static void main(String[] args)
    {
        System.out.print("fib(45) : "+fib(45));
    }
}

/*
This is slow since we are calculating same values again and again many times.
 */
public class FibonacciRecursive
{
    private static int fib(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        else
            return fib(n-1)+fib(n-2);
    }

    public static void main(String[] args)
    {
        System.out.printf("fib(45) : "+fib(45));
    }
}

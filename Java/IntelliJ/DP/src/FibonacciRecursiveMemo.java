/*
This is faster version because here as we computer fib(n) we store that value in table.
when we need that value again we just retrieve it from table.
 */
public class FibonacciRecursiveMemo
{
    private static int[] table;
    private static int fib(int n)
    {
        // if table[n] doesn't contain a valid entry than update it.
        // otherwise return the table[n]
        if(table[n]==-1)
        {
            table[n]=fib(n-1)+fib(n-2);
        }
        return table[n];
    }

    public static void main(String[] args)
    {
        table = new int[45+1];
        table[0]=0;
        table[1]=1;
        for(int i=2;i<46;i++)
        {
            table[i]=-1;
        }

        System.out.printf("fib(45) : "+fib(45));
    }
}

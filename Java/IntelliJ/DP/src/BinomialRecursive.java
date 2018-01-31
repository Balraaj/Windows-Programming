/*
This is simple recursive solution. it calculates same values many times, hence its slow.
 */
public class BinomialRecursive
{
    private static int bin(int n,int r)
    {
        if((n==0)||(r==0)||(r==n))
        {
            return 1;
        }
        if(r==1)
        {
            return n;
        }

        return bin(n-1,r-1)+bin(n-1,r);
    }

    public static void main(String[] args)
    {
        System.out.println("bin(10,5) : "+bin(100,50));
    }
}

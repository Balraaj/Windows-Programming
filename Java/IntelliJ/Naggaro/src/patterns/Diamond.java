package patterns;

/**
 * Created by Balraj on 04-Mar-18.
 */
public class Diamond
{
    private static void printDiamond(int n)
    {
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if((j>=n/2-i)&&(j<=n/2+i))
                {
                    System.out.print(" ");
                }
                else
                {
                    System.out.print("*");
                }
            }
            System.out.println();
        }

        for(int i=1;i<=n/2;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if((j>=i)&&(j<n-i+1))
                {
                    System.out.print(" ");
                }
                else
                {
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        printDiamond(20);
    }
}

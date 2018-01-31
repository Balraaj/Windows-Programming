
public class BinomialRecursiveMemo
{
    private static int[][] table = new int[105][105];

    private static int bin(int n,int r)
    {
        if(table[n][r]==-1)
        {
            table[n][r]=bin(n-1,r-1)+bin(n-1,r);
        }
        return table[n][r];
    }

    public static void main(String[] args)
    {
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if((i==0)||(j==0)||(i==j))
                {
                    table[i][j]=1;
                }
                else
                {
                    table[i][j]=-1;
                }
            }
        }

        System.out.println("bin(10,5) : "+bin(10,5));
    }
}

/*
    Given two strings X and Y, determine the longest common subsequence of both the strings.
 */

public class LCS
{
    private static char[][] Direction; // array to store direction information to print the LCS.
    private static final char MATCH = 'm';
    private static final char UP = 'u';
    private static final char SIDE = 's';

    private static void LCSLength(String X, String Y)
    {
        int[][] Length = new int[X.length()+1][Y.length()+1];

        // set the first row and column to 0 for the base case.
        for(int i=0;i<=X.length();i++)
        {
            Length[i][0]=0;
        }
        for(int i=0;i<=Y.length();i++)
        {
            Length[0][i]=0;
        }

        Direction = new char[X.length()+1][Y.length()+1];

        for(int i=1;i<=X.length();i++)
        {
            for(int j=1;j<=Y.length();j++)
            {
                if(X.charAt(i-1)==Y.charAt(j-1))
                {
                    Length[i][j]=Length[i-1][j-1]+1;
                    Direction[i][j]=MATCH;
                }
                else if(Length[i-1][j]>=Length[i][j-1])
                {
                    Length[i][j]=Length[i-1][j];
                    Direction[i][j]=UP;
                }
                else
                {
                    Length[i][j]=Length[i][j-1];
                    Direction[i][j]=SIDE;
                }
            }
        }

        /* This code prints the length table
        for(int i=0;i<X.length()+1;i++)
        {
            for(int j=0;j<Y.length()+1;j++)
            {
                System.out.print(Length[i][j]+" ");
            }

            System.out.println();
        } */
    }

    private static void printLCS(String X,int m,int n)
    {
        if((m!=0)&&(n!=0))
        {
            if(Direction[m][n] == MATCH)
            {
                printLCS(X, m - 1, n - 1);
                System.out.print(X.charAt(m - 1));
            }
            else if(Direction[m][n] == UP)
            {
                printLCS(X, m - 1, n);
            }
            else
            {
                printLCS(X, m, n - 1);
            }
        }
    }

    public static void main(String[] args)
    {
        String X = "AaBCxxxHT";
        String Y = "ADDDDDBCCCCCxRRRRRHdddddxddT";
        LCSLength(X,Y);
        printLCS(X,X.length(),Y.length());
    }
}

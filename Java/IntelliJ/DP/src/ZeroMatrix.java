/**
 * Created by Balraj on 29-Jan-18.
 */
public class ZeroMatrix
{
    private static void checkZeros(int[][] matrix)
    {
        boolean rowHasZero = false;
        boolean columnHasZero = false;

        for(int i=0;i<matrix[0].length;i++)
        {
            if(matrix[0][i]==0)
            {
                rowHasZero=true;
            }
        }

        for(int i=0;i<matrix.length;i++)
        {
            if(matrix[i][0]==0)
            {
                columnHasZero=true;
            }
        }

        for(int i=1;i<matrix.length;i++)
        {
            for(int j=1;j<matrix[0].length;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=0;i<matrix[0].length;i++)
        {
            if(matrix[0][i]==0)
            {
                nullifyColumn(matrix,i);
            }
        }
        for(int i=0;i<matrix.length;i++)
        {
            if(matrix[i][0]==0)
            {
                nullifyRow(matrix,i);
            }
        }

        if(rowHasZero)
        {
            nullifyRow(matrix,0);
        }
        if(columnHasZero)
        {
            nullifyColumn(matrix,0);
        }

    }

    private static void nullifyRow(int[][] matrix,int row)
    {
        for(int i=0;i<matrix[0].length;i++)
        {
            matrix[row][i]=0;
        }
    }

    private static void nullifyColumn(int[][] matrix,int column)
    {
        for(int i=0;i<matrix.length;i++)
        {
            matrix[i][column]=0;
        }
    }

    public static void main(String[] args)
    {
        int[][] arr = {{1,0,3,4},{0,0,1,2},{1,2,0,4},{1,1,1,1}};
        System.out.println("-------- matrix before zeroing --------");
        for(int i=0;i<arr.length;i++)
        {
            System.out.print("         ");
            for(int j=0;j<arr[0].length;j++)
            {
                System.out.print(arr[i][j]+" ");
            }

            System.out.println();
        }

        checkZeros(arr);

        System.out.println("-------- matrix after zeroing --------");
        for(int i=0;i<arr.length;i++)
        {
            System.out.print("         ");
            for(int j=0;j<arr[0].length;j++)
            {
                System.out.print(arr[i][j]+" ");
            }

            System.out.println();
        }
    }
}

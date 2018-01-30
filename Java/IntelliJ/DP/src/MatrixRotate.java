/**
 * Created by Balraj on 29-Jan-18.
 *
 * Given a matrix of size N X N , rotate it by 90 degree.
 * try to solve it in place
 */
public class MatrixRotate
{
    private static void rotateMatrix(int[][] matrix)
    {
        int firstRow=0;
        int lastRow=matrix[0].length-1;
        int firstColumn=0;
        int lastColumn=matrix[0].length-1;

        while(firstRow<lastRow)
        {
            int j=0;
            while(firstColumn+j<lastColumn)
            {
                int temp=matrix[firstRow][firstColumn+j];
                matrix[firstRow][firstColumn+j]=matrix[firstRow+j][lastColumn];
                matrix[firstRow+j][lastColumn]=matrix[lastRow][lastColumn-j];
                matrix[lastRow][lastColumn-j]=matrix[lastRow-j][firstColumn];
                matrix[lastRow-j][firstColumn]=temp;
                j++;
            }
            firstRow++;
            firstColumn++;
            lastRow--;
            lastColumn--;
        }
    }

    public static void main(String[] args)
    {
        int width=7;
        int[][] arr = new int[width][width];
        int number=11;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<width;j++)
            {
                arr[i][j]=number++;
            }
        }

        System.out.println("-----------Your matrix before rotation------------");
        for(int i=0;i<width;i++)
        {
            System.out.print("                ");
            for(int j=0;j<width;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }

        rotateMatrix(arr);

        System.out.println("\n\n-----------Your matrix after rotation------------");
        for(int i=0;i<width;i++)
        {
            System.out.print("                 ");
            for(int j=0;j<width;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }

    }
}

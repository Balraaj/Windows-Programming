/**
 * Created by Balraj on 19-Feb-18.
 */
public class MatrixPrintSpiral
{
    private static void printSpiralRecursive(int[][] arr,int sr,int er,int sc,int ec)
    {
        if((sr<=er)&&(sc<=ec))
        {
            // print the first row of matrix given by sr
            for(int i=sc;i<ec;i++)
            {
                System.out.print(arr[sr][i]+" ");
            }

            // print the last column of the matrix given by ec
            for(int i=sr;i<er;i++)
            {
                System.out.print(arr[i][ec]+" ");
            }

            // print the last row of the matrix given by er
            for(int i=ec;i>sc;i--)
            {
                System.out.print(arr[er][i]+" ");
            }

            // print the first column of the matrix given by sc
            for(int i=er;i>sr;i--)
            {
                System.out.print(arr[i][sc]+" ");
            }

            System.out.println();
            printSpiralRecursive(arr,sr+1,er-1,sc+1,ec-1);
        }
    }

    private static void printSpiralIterative(int[][] arr)
    {
        int sr=0;
        int er=arr.length-1;
        int sc=0;
        int ec=arr[0].length-1;

        while((sr<=er)&&(sc<=ec))
        {
            for(int i=sc;i<ec;i++)
            {
                System.out.print(arr[sr][i]+" ");
            }

            for(int i=sr;i<er;i++)
            {
                System.out.print(arr[i][ec]+" ");
            }

            for(int i=ec;i>sc;i--)
            {
                System.out.print(arr[er][i]+" ");
            }

            for(int i=er;i>sr;i--)
            {
                System.out.print(arr[i][sc]+" ");
            }

            System.out.println();
            sr++;
            er--;
            sc++;
            ec--;
        }
    }
    public static void main(String[] args)
    {
        int[][] arr =  {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                         {13,14,15,16},
                {17,18,19,20},
                {21,22,23,24},
                {25,26,27,28}};
        //printSpiralRecursive(arr,0,arr.length-1,0,arr[0].length-1);
        printSpiralIterative(arr);
    }
}

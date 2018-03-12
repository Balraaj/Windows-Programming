/**
 * Created by Balraj on 19-Feb-18.
 * Given a matrix of size M X M , rotate a sub matrix of size N X N where M>=N
 */
public class MatrixRotateSubMatrix
{
    private static void rotateMatrix(int[][]arr,int size,int sr,int sc)
    {
        int er = sr+size-1;
        int ec = sc+size-1;

        while(sr<er)
        {
            int j=0;
            while(sc+j<ec)
            {
                int temp = arr[sr][sc+j];
                arr[sr][sc+j]=arr[sr+j][ec];
                arr[sr+j][ec]=arr[er][ec-j];
                arr[er][ec-j]=arr[er-j][sc];
                arr[er-j][sc]=temp;
                j++;
            }

            sr++;
            er--;
            sc++;
            ec--;
        }
    }

    public static void main(String[] args)
    {
        int[][] arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        for(int[] i:arr)
        {
            for(int j:i)
            {
                System.out.print(j+" ");
            }
            System.out.println();
        }
        rotateMatrix(arr,2,1,1);
        System.out.println();
        System.out.println();
        for(int[] i:arr)
        {
            for(int j:i)
            {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}

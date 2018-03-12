/**
 * Created by Balraj on 18-Feb-18.
 * Given three sorted arrays print the common elements in all three arrays
 */
public class ArrayPrintCommonElements
{
    private static void printCommon(int[] A,int[] B,int[] C)
    {
        int i=0,j=0,k=0;
        while(i<A.length && j<B.length && k<C.length)
        {
            if((A[i]==B[j]) && (B[j]==C[k]))
            {
                System.out.print(A[i]+" ");
                i++;
                j++;
                k++;
            }
            else if(A[i]<B[j])
            {
                i++;
            }
            else if(B[j]<C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
    }

    public static void main(String[] args)
    {
        int[] A={1,4,6,88,555};
        int[] B={2,3,4,88,44};
        int[] C={4,23,34,56,78,88};
        printCommon(A,B,C);
    }
}

/**
 * Created by Balraj on 18-Feb-18.
 * Given three arrays print the five largest elements
 */
public class ArrayFindFiveLargestElementsFromThreeSortedArrays
{
    private static void printLargest(int[] A,int[] B,int[] C)
    {
        int i=A.length-1;
        int j=B.length-1;
        int k=C.length-1;

        int count=5;
        while(count>=0)
        {
            if(A[i]>B[j])
            {
                if(A[i]>C[k])
                {
                    System.out.print(A[i]+" ");
                    i--;
                }
                else
                {
                    System.out.print(C[k]+" ");
                    k--;
                }
            }
            else
            {
                if(B[j]>C[k])
                {
                    System.out.print(B[j]+" ");
                    j--;
                }
                else
                {
                    System.out.print(C[k]+" ");
                    k--;
                }
            }
            count--;
        }
    }

    public static void main(String[] args)
    {
        int[] A={1,5,99,133,200,204,299};
        int[] B={1,2,3,4,5};
        int[] C={50,60,61,63,65};

        printLargest(A,B,C);
    }

}

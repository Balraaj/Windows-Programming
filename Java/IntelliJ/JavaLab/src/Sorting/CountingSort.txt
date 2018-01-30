package Sorting;

public class CountingSort
{
    static int[] sort(int A[],int k)
    {
        int[] C = new int[k+1];
        for(int i=0;i<k+1;i++)
        {
            C[i]=0;
        }

        for(int i=0;i<A.length;i++)
        {
            C[A[i]] = C[A[i]]+1;
        }

        for(int i=1;i<k+1;i++)
        {
            C[i]=C[i]+C[i-1];
        }

        int[] B = new int[A.length];

        for(int i=B.length-1;i>=0;i--) //This is stable
        {
            B[C[A[i]]-1] = A[i];
            C[A[i]] = C[A[i]]-1;
        }

        return B;


    public static void main(String[] args)
    {
        int[] arr = {12,9,23,34,12,2,3,3,5,6,34,12,13,21};
        int[] temp = sort(arr,34);

        for(int i=0;i<temp.length;i++)
        {
            System.out.print(" "+temp[i]);
        }
    }
}

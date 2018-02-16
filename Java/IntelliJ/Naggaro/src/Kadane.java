/**
 * Created by Balraj on 16-Feb-18.
 */
public class Kadane
{
    private static void findMaxSumSubArray(int[] arr)
    {
        int start = 0;
        int end = 0;
        int s = 0;
        int maxSoFar = arr[0];
        int maxEndingHere = 0;

        for(int i =0;i<arr.length;i++)
        {
            maxEndingHere+=arr[i];
            if(maxSoFar<maxEndingHere)
            {
                maxSoFar=maxEndingHere;
                start=s;
                end=i;
            }
            if(maxEndingHere<0)
            {
                maxEndingHere=0;
                s=i+1;
            }
        }

        System.out.println("Maximum sum : " +maxSoFar);
        System.out.println("Starts at : "+start);
        System.out.println("Ends at : "+end);
    }

    public static void main(String[] args)
    {
        int[] arr = {-13,-3,-6,9,7,-1,0};
        findMaxSumSubArray(arr);
    }
}

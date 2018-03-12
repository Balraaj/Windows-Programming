/**
 * Created by Balraj on 16-Feb-18.
 */
public class Kadane
{
    private static void findMaxSumSubArray(int[] arr)
    {
        int globalStart = 0;
        int globalEnd = 0;
        int localStart = 0;
        int globalMax = arr[0];
        int localMax = 0;

        for(int i =0;i<arr.length;i++)
        {
            localMax+=arr[i];
            if(globalMax<localMax)
            {
                globalMax=localMax;
                globalStart=localStart;
                globalEnd=i;
            }
            if(localMax<0)
            {
                localMax=0;
                localStart=i+1;
            }
        }

        System.out.println("Maximum sum : " +globalMax);
        System.out.println("Starts at : "+globalStart);
        System.out.println("Ends at : "+globalEnd);
    }

    public static void main(String[] args)
    {
        int[] arr = {-13,-3,-6,9,7,-1,0};
        findMaxSumSubArray(arr);
    }
}

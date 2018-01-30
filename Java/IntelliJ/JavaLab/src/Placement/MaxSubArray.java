package Placement;

public class MaxSubArray
{

    private static int[] findMaxCrossingSubArray(int[] arr,int low,int mid,int high)
    {
        int leftSum = -99999;
        int leftIndex = 0;
        int sum = 0;

        for(int n=mid;n>=low;n--)
        {
            sum = sum + arr[n];

            if(sum>leftSum)
            {
                leftSum=sum;
                leftIndex = n;
            }
        }

        sum = 0;
        int rightSum = -99999;
        int rightIndex = 0;

        for(int n = mid+1;n<=high;n++)
        {
            sum=sum+arr[n];
            if(sum>rightSum)
            {
                rightSum=sum;
                rightIndex=n;
            }
        }

        return new int[] {leftIndex,rightIndex,leftSum+rightSum};
    }

    private static int[] findMaxSubArray(int[] arr,int low,int high)
    {
        final int SUM = 2;
        if(low==high)
        {
            return new int[] {low,high,arr[low]};
        }
        else
        {
            int mid = (low+high)/2;
            int[] left = findMaxSubArray(arr,low,mid);
            int[] right = findMaxSubArray(arr,mid+1,high);
            int[] cross = findMaxCrossingSubArray(arr,low,mid,high);

            if((left[SUM]>=right[SUM])&&(left[SUM]>=cross[SUM]))
            {
                return left;
            }
            else if((right[SUM]>=left[SUM])&&(right[SUM]>=cross[SUM]))
            {
                return right;
            }
            else
            {
                return cross;
            }

        }
    }

    public static void main(String[] args)
    {
        int[] arr = {-12,-6,34,-4,40,-9};

        int[] temp = findMaxSubArray(arr,0,5);

        System.out.print("Maximum sum is : "+temp[2]);
        System.out.print("\nStart index : "+temp[0]);
        System.out.print("\nEnd index : "+temp[1]);
    }
}

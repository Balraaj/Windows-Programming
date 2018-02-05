/**
 * Created by Balraj on 05-Feb-18.
 */
public class MaximumSubArray
{
    private static final int START=0;
    private static final int END=1;
    private static final int SUM=2;

    private static int[] findMaxSubArray(int[] arr,int start,int end)
    {
        if(start==end)
        {
            return new int[]{start,end,arr[start]};
        }
        else
        {
            int mid = (start+end)/2;
            int[] leftSub=findMaxSubArray(arr,start,mid);
            int[] rightSub=findMaxSubArray(arr,mid+1,end);
            int[] cross=findMaxCross(arr,start,mid,end);

            if((leftSub[SUM]>rightSub[SUM])&&(leftSub[SUM]>cross[SUM]))
            {
                return leftSub;
            }
            else if((rightSub[SUM]>leftSub[SUM])&&(rightSub[SUM]>cross[SUM]))
            {
                return rightSub;
            }
            else
            {
                return cross;
            }
        }
    }

    private static int[] findMaxCross(int[] arr,int start,int mid,int end)
    {
        int leftSum=-50000;
        int sum=0;
        int leftIndex=0;

        for(int i=mid;i>=start;i--)
        {
            sum+=arr[i];
            if(sum>leftSum)
            {
                leftSum=sum;
                leftIndex=i;
            }
        }

        int rightSum=-50000;
        int rightIndex=0;
        sum=0;

        for(int i=mid+1;i<=end;i++)
        {
            sum+=arr[i];
            if(sum>rightSum)
            {
                rightSum=sum;
                rightIndex=i;
            }
        }

        return new int[]{leftIndex,rightIndex,leftSum+rightSum};
    }

    public static void main(String[] args)
    {
        int[] arr = {3,4,-6,4,12,5,-18};
        int[] result =  findMaxSubArray(arr,0,arr.length-1);
        System.out.println("Start index is : "+result[START]);
        System.out.println("End index is : "+result[END]);
        System.out.println("Sum is : "+result[SUM]);
    }
}

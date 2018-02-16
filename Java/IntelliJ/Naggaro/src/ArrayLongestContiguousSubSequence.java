/**
 * Created by Balraj on 12-Feb-18.
 * Given an unsorted array find the length of longest contiguous sub sequence.
 * if givne array is 45,12,1,5,2,3,4,5,644,3 then longest contiguous sub sequence have length 4 [2,3,4,5]
 */
public class ArrayLongestContiguousSubSequence
{
    private static final int COUNT = 2;
    private static int[] longestContiguousSubSequence(int[] arr,int start,int end)
    {
        if(start==end)
        {
            return new int[] {start,end,1};
        }
        else
        {
            int mid = (start+end)/2;
            int[] left = longestContiguousSubSequence(arr,start,mid);
            int[] right = longestContiguousSubSequence(arr,mid+1,end);
            int[] cross = longestCrossingSubSequence(arr,start,mid,end);

            if((left[COUNT]>right[COUNT])&&(left[COUNT]>cross[COUNT]))
            {
                return left;
            }
            else if((right[COUNT]>left[COUNT])&&(right[COUNT]>cross[COUNT]))
            {
                return right;
            }
            else
            {
                return cross;
            }
        }
    }

    private static int[] longestCrossingSubSequence(int[] arr,int start,int mid,int end)
    {
        int leftCount = 0;
        int leftIndex = mid;
        for(int i=mid-1;i>=start;i--)
        {
            if(arr[i]==arr[i+1]-1)
            {
                leftCount++;
                leftIndex=i;
            }
        }

        int rightCount = 0;
        int rightIndex = mid;
        for(int i=mid+1;i<end;i++)
        {
            if(arr[i]==arr[i-1]+1)
            {
                rightCount++;
                rightIndex=i;
            }
        }

        return new int[] {leftIndex,rightIndex,leftCount+rightCount};
    }


    public static void main(String[] args)
    {
        int[] arr = {1,9,1,2,3,4,5,6,7,11};
        int[] result = longestContiguousSubSequence(arr,0,arr.length-1);
        System.out.println("Length of longest sub Sequence is : "+result[COUNT]);
        System.out.print("It starts at : "+result[0]+" and ends at : "+result[1]);
    }
}

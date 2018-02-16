/**
 * Created by Balraj on 10-Feb-18.
 * Given a sorted and rotated array search it for a given value.
 */
public class BinarySearchSortedRotated
{
    private static final int NOTFOUND = -1;
    private static int find(int[] arr,int start,int end,int key)
    {
        if(start>end)
            return -1;

        int mid = (start+end)/2;

        if(arr[mid]==key)
            return mid;

        if(arr[start]<=arr[mid])
        {
            if((arr[start]<=key)&&(arr[mid]>=key))
            {
                return find(arr,start,mid-1,key);
            }
            else
            {
                return find(arr,mid+1,end,key);
            }
        }
        else
        {
            if((arr[mid]<=key)&&(arr[end]>=key))
            {
                return find(arr,mid+1,end,key);
            }
            else
            {
                return find(arr,start,mid-1,key);
            }
        }
    }

    private static int findIterative(int[] arr,int value)
    {
        int start = 0;
        int end = arr.length-1;
        while(start<end)
        {
            int mid = (start+end)/2;
            if(arr[mid]==value) return mid;

            if(arr[mid]>=arr[start]) // check which part is sorted
            {
                if((value>=arr[start])&&(value<=arr[mid]))
                {
                    end = mid;
                }
                else
                {
                    start = mid+1;
                }
            }
            else
            {
                if((value>=arr[mid])&&(value<=arr[end]))
                {
                    start = mid;
                }
                else
                {
                    end = mid-1;
                }
            }
        }

        return start;
    }

    public static void main(String[] args)
    {
        int[] arr={7,8,1,2,2,3,4,6};
        System.out.println("1 lies at : "+findIterative(arr,5));
    }

}

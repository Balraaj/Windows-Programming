/**
 * Created by Balraj on 10-Feb-18.
 * Given a sorted and rotated array search it for a given value.
 */
public class BinarySearchSortedRotated
{
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

    public static void main(String[] args)
    {
        int[] arr={7,8,1,2,2,3,4,5};
        System.out.println("1 lies at : "+find(arr,0,arr.length-1,2));
    }

}

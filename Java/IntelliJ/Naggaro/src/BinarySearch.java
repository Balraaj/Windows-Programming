/**
 * Created by Balraj on 01-Feb-18.
 */
public class BinarySearch
{
    private static final int NOTFOUND = -1;
    private static int search(int[] arr,int value)
    {
        int start=0;
        int end=arr.length-1;
        int mid;

        while(start<=end)
        {
            mid=(start+end)/2;
            if(arr[mid]==value)
            {
                return mid;
            }
            else if(arr[mid]>value)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }

        return BinarySearch.NOTFOUND;
    }

    public static void main(String[] args)
    {
        int[] arr ={1,2,3,4,5,6,7,10};
        int index = search(arr,8);
        if(index==-1)
        {
            System.out.println("Not found");
        }
        else
        {
            System.out.println("Index of 8 is : "+index);
        }
    }
}

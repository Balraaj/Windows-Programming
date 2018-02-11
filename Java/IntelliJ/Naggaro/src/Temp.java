/**
 * Created by Balraj on 11-Feb-18.
 */
public class Temp
{
    private static int search(int[] arr, int start,int end,int value)
    {
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]>value)
            {
                end=mid-1;
            }
            else if(arr[mid]<value)
            {
                start=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    private static int searchRecursive(int[] arr,int start,int end,int value)
    {
        if(start>end)
        {
            return -1;
        }

        int mid=(start+end)/2;
        if(arr[mid]==value)
        {
            return mid;
        }
        else if(arr[mid]>value)
        {
            return searchRecursive(arr,start,mid-1,value);
        }
        else
        {
            return searchRecursive(arr,mid+1,end,value);
        }
    }

    private static int searchRotationPoint(int[] arr)
    {
        int start = 0;
        int end = arr.length-1;

        // keep going while arr[start]>arr[end]

        while(arr[start]>arr[end])
        {
            int mid=(start+end)/2;

            if(arr[mid]>arr[start])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }

        return start;
    }

    private static int searchClosestIndex(int[] arr,int value)
    {
        int start = 0;
        int end = arr.length-1;

        if(value<arr[start]) return 0;
        if(value>arr[end]) return end;

        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]>value)
            {
                end=mid-1;
            }
            else if(arr[mid]<value)
            {
                start=mid+1;
            }
            else
            {
                return mid;
            }
        }

        return ((arr[start]-value)>value-arr[end])?end:start;
    }
    public static void main(String[] args)
    {
        int[] arr={4,6,7,8,9,10,13};
        int value = 5;
        //System.out.print(value+" is found at : "+searchRecursive(arr,0,arr.length-1,value));
        //System.out.println("Rotation point of array is : "+searchRotationPoint(arr));

        System.out.println("Closest element to "+value+" is at : "+searchClosestIndex(arr,value));
    }
}

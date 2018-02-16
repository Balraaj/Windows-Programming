/**
 * Created by Balraj on 12-Feb-18.
 */
public class Temp
{
    private static int findIndex(int[] arr,int value)
    {
        if(value<arr[0]) return 0;
        if(value>arr[arr.length-1]) return -1;

        int start = 0;
        int end = arr.length-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[mid]==value)
            {
                return mid;
            }
            else if(value>arr[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return start;
    }

    public static void main(String[] args)
    {
        int[] arr = {1,3,5,7,9,11,15,19};
        int value = 2;
        System.out.println("Ceiling of "+value+" is : "+findIndex(arr,value));
    }
}

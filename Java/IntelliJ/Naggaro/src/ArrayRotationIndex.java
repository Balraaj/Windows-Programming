/**
 * Created by Balraj on 10-Feb-18.
 * Given a sorted, rotated array find the rotation index.
 */
public class ArrayRotationIndex
{
    private static int findIndex(int[] arr)
    {
        int start = 0;
        int end = arr.length-1;
        while(arr[start]>arr[end])
        {
            int mid = (start+end)>>>1;
            if(arr[mid]>arr[start])
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }

    public static void main(String[] args)
    {
        int[] arr = {1};
        System.out.println("Rotation index is : "+findIndex(arr));
    }
}

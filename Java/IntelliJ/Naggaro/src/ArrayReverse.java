import java.util.Arrays;

/**
 * Created by Balraj on 12-Feb-18.
 * Reverse the given array.
 */
public class ArrayReverse
{
    // This method can be modified to use with the strings.
    private static void reverse(int[] arr)
    {
        int i=0;
        int j=arr.length-1;

        while(i<j)
        {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }

    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        reverse(arr);
        System.out.println(Arrays.toString(arr));
    }
}

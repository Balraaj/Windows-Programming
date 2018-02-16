import java.util.Arrays;

/**
 * Created by Balraj on 12-Feb-18.
 * Given an unsorted array of positive and negative numbers, rearrange the array such that the negative numbers
 * come before the positive numbers.
 */
public class ArrayRearrangePositiveNegative
{
    /*
        This is partition method from quick sort. we can rearrange positive and negative numbers by using 0 as pivot.
        Problem with this approach is that its not stable.
     */
    private static void rearrangeQuickSortStyle(int[] arr)
    {
        int value = 0;
        int index = 0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]<value)
            {
                int temp = arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
                index++;
            }
        }
    }

    /*
        Following methods implement a modified merge sort to solve this problem.
        idea is to divide the array in two parts, one negative and another positive.
        after this step we will have left and right sub arrays as LN LP RN RP.
        we want to change this to LN RN LP RP. this is same problem as rotating the sub array from LP RN -> RN LP
     */
    private static void rearrange(int[] arr,int start,int end)
    {
        if(start<end)
        {
            int mid = (start+end)/2;
            rearrange(arr,start,mid);
            rearrange(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }

    private static void merge(int[] arr,int start,int mid,int end)
    {
        int i = start;
        int j = mid+1;

        while((i<=mid)&&(arr[i]<0))
        {
            i++;
        }
        while((j<=end)&&(arr[j]<0))
        {
            j++;
        }

        reverse(arr,i,mid);
        reverse(arr,mid+1,j-1);
        reverse(arr,i,j-1);
    }

    private static void reverse(int[] arr,int start,int end)
    {
        while(start<end)
        {
            int temp = arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args)
    {
        int[] arr ={-9,-8,-123,-5};
        rearrange(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
}

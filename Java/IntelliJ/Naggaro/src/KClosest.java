/**
 * Created by Balraj on 01-Feb-18.
 *
 * Given a sorted array and a value, this method finds the index of value if it's present in the array.
 * if the value is not present in the array then method returns the index of the element closest to the value.
 */
public class KClosest
{
    private static int findClosest(int[] arr,int value)
    {
        /*
            This method returns the index of value if it exists in the array or the index of element which is
            closest to the value. it is a modified binary search.
         */
        if(value<arr[0])
        {
            return 0; // if value is smaller than all elements then return first index
        }

        if(value>arr[arr.length-1])
        {
            return arr.length-1; // if value is greater than all elements then return last index
        }

        int start,end,mid;
        start = 0;
        end = arr.length-1;

        while(start<=end)
        {
            mid=(start+end)/2;
            if(arr[mid]==value)
            {
                return mid; // if value is found then return it's index
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

        // if value is not found then start and end points to the two closest elements to value.
        // we simply has to calculate difference of these two from the value.
        // we return the index of element whichever has smaller difference.
        return (arr[start]-value)<(value-arr[end])?start:end;
    }

    private static void printKClosest(int[] arr,int value,int k)
    {
        int i = findClosest(arr,value); // find index of value or its closest value
        int j=i+1;
        int count = 0;

        while(((i>=0)||(j<arr.length))&&(count<k))
        {
            if(i<0)
            {
                while((j<arr.length)&&(count<5))
                {
                    System.out.println(arr[j]);
                    count++;
                    j++;
                }
            }
            else if(j==arr.length)
            {
                while((i>=0)&&(count<5))
                {
                    System.out.println(arr[i]);
                    count++;
                    i--;
                }
            }
            else
            {
                if((value-arr[i]<(arr[j]-value)))
                {
                    System.out.println(arr[i]);
                    i--;
                }
                else
                {
                    System.out.println(arr[j]);
                    j++;
                }
                count++;
            }
        }
    }
    public static void main(String[] args)
    {
        int[] arr = {1,2,3,6,9,13,34,37,56};

        printKClosest(arr,9,4);

    }
}

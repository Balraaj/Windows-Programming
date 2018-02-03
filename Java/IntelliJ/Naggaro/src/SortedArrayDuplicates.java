/**
 * Created by Balraj on 03-Feb-18.
 * Given a sorted array remove all the duplicate values. (NAGARRO 6)
 */
public class SortedArrayDuplicates
{
    private static int removeDuplicatesInPlace(int[] arr)
    {
        /*
            This method works in place and returns the length of modified array.
         */
        int index=1; // we don't need to check the first element because even if all the elements are same
                    //  still first element will be in output.
        for(int i=1;i<arr.length;i++)
        {
            if(arr[i]!=arr[i-1])
            {
                arr[index++]=arr[i];
            }
        }
        return index;
    }

    private static int removeDuplicates(int[] arr, int[] modifiedArray)
    {
        /*
            This method requires one extra array of the same size as the original array.
            it returns the size of the modified array.
         */
        modifiedArray[0]=arr[0];
        int index=1;
        for(int i=1;i<arr.length;i++)
        {
            if(arr[i]!=arr[i-1])
            {
                modifiedArray[index++]=arr[i];
            }
        }
        return index;
    }

    public static void main(String[] args)
    {
        int[] arr = {2,2,2,3,4,4,5,5,6,7,8,9,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
                ,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13};
        int[] modifiedArray = new int[arr.length];
        int index = removeDuplicates(arr,modifiedArray);
        for(int i=0;i<index;i++)
        {
            System.out.print(modifiedArray[i]+" ");
        }
    }
}

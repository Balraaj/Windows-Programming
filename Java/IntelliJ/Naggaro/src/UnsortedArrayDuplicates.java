import java.util.HashSet;

/**
 * Created by Balraj on 03-Feb-18.
 * Given an unsorted array remove all the duplicates.
 */
public class UnsortedArrayDuplicates
{
    private static int removeDuplicates(int[] arr)
    {
        HashSet<Integer> mySet = new HashSet<>();
        int index = 0;
        for(int i=0;i<arr.length;i++)
        {
            if(!mySet.contains(arr[i])) // check if element is already encountered
            {
                mySet.add(arr[i]);
                arr[index++]=arr[i];
            }
        }
        return index;       // return size of the modified array
    }

    public static void main(String[] args)
    {
        int[] arr = {23,1,2,23,2,9,1,34,34,2,36};
        int index = removeDuplicates(arr);
        for(int i=0;i<index;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}

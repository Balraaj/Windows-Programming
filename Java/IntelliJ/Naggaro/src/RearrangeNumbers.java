import java.util.Arrays;

/*
Given an unsorted array of positive and negative numbers, rearrange the array such that positive and negative numbers
occupy the alternate positions.
 */

class RearrangeNumbers
{
    // This is modified partition method from quick sort. it partitions the array using pivot = 0.
    private static int partition(int[] arr)
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
        return index;
    }

    private static void rearrange(int[] arr)
    {
        int partIndex = partition(arr);
        int i = 0;

        while((partIndex<arr.length)&&(i<partIndex)&&(arr[i]<0))
        {
            int temp = arr[i];
            arr[i]=arr[partIndex];
            arr[partIndex]=temp;
            partIndex++;
            i+=2;
        }
    }

    public static void main(String[] args)
    {
        int[] arr = {-1,-3,-5,-67,-5,5};
        rearrange(arr);
        System.out.println(Arrays.toString(arr));
    }
}
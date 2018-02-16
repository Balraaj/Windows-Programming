import java.util.Arrays;

/**
 * Created by Balraj on 12-Feb-18.
 */
public class ArraySortWaveForm
{
    private static void swap(int[] arr,int firstIndex,int secondIndex)
    {
        int temp = arr[firstIndex];
        arr[firstIndex]=arr[secondIndex];
        arr[secondIndex]=temp;
    }

    private static void sortWave(int[] arr)
    {
        for(int i=0;i<arr.length;i+=2)
        {
            if((i>0)&&(arr[i-1]>arr[i]))
            {
                swap(arr,i-1,i);
            }
            if((i<arr.length-1)&&(arr[i+1]>arr[i]))
            {
                swap(arr,i,i+1);
            }
        }
    }

    public static void main(String[] args)
    {
        int[] arr={12,1200,14,150,160,1,189};
        sortWave(arr);
        System.out.println(Arrays.toString(arr));
    }
}

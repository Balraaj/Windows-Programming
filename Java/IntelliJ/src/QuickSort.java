/**
 * Created by Balraj on 15-08-2016.
 */

public class QuickSort
{
    static int part(int arr[],int beg,int end)
    {
        int index = beg;
        int pivot = arr[end];
        for(int i=beg;i<end;i++)
        {
            if(arr[i]<pivot)
            {
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
                index++;
            }
        }

       int temp = arr[index];
        arr[index] = pivot;
        arr[end] = temp;
        return index;

    }

    static void qsort(int arr[],int beg,int end)
    {
        if(beg<end)
        {
            int index = part(arr,beg,end);
            qsort(arr, beg, index-1);
            qsort(arr, index+1, end);
        }
    }

    public static void main(String[] args)
    {
        int arr[] = {1234,1,34536,3,2,9,10};
        qsort(arr, 0, 6);

        for(int i=0;i<7;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}




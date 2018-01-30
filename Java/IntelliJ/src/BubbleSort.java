/**
 * Created by Balraj on 19-08-2016.
 */
public class BubbleSort
{
    static void bsort(int arr[])
    {
        for(int i=0;i<arr.length-1;i++)
        {
            boolean flag = false;

            for(int j=0;j<arr.length-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    flag = true;
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }

            if(!flag)
            {
                break;
            }
        }
    }

    public static void main(String [] args)
    {
        int arr[] = {123,2,-333333,34,6,999,76,-1};
        bsort(arr);

        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

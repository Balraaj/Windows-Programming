/**
 * Created by Balraj on 19-08-2016.
 */
public class SelSort
{
    static void ssort(int arr[])
    {
        for(int i=0;i<arr.length-1;i++)
        {
            int index = i;

            for(int j=i+1;j<arr.length;j++)
            {
                if(arr[j]<arr[index])
                {
                    index = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }

    public static void main(String [] args)
    {
        int arr[] = {123,3,2,908,456456,-9,-1,12312};
        ssort(arr);

        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);

        }
    }
}

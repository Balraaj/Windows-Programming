/**
 * Created by Balraj on 15-08-2016.
 */
public class SelectionSort
{
   static void ssort(int arr[])
    {
        int n = arr.length;
        for(int i=0;i<n-1;i++)
        {
            int index = i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[index]>arr[j])
                {
                    index=j;
                }
            }

            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args)
    {
      int arr[] = {123,2,2342,5,6};
        ssort(arr);

        int n = arr.length;
        for(int i=0;i<n;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

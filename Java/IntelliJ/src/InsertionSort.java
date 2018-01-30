/**
 * Created by Balraj on 19-08-2016.
 */
public class InsertionSort
{
    static void isort(int arr[])
    {
        int n = arr.length;

        for(int i = 1;i<n;i++)
        {
            int key = arr[i];
            int j = i-1;

            while((j>=0)&&(key<arr[j]))
            {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = key;
        }
    }

    public static void main(String [] args)
    {
        int arr[] = {123,1,3,456,77,6,2-3,-2,-76};
        isort(arr);

        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

/**
 * Created by Balraj on 15-08-2016.
 */
public class MergeSort
{
    static void merge(int arr1[],int arr2[], int arr[])
    {
        int n = arr1.length;
        int m = arr2.length;

        int x,y,z;
        x = y = z = 0;

        while((x<n)&&(y<m))
        {
            if(arr1[x]<arr2[y])
            {
                arr[z++] = arr1[x++];
            }
            else
            {
                arr[z++] = arr2[y++];
            }
        }

        while(x<n)
        {
            arr[z++] = arr1[x++];
        }

        while(y<m)
        {
            arr[z++] = arr2[y++];
        }
    }


    static void msort(int arr[])
    {
        int size = arr.length;

        if(size>1)
        {
            int n = size/2;
            int m = size-n;

            int arr1[] = new int[n];
            int arr2[] = new int[m];

            int k = 0;

            for(int i=0;i<n;i++)
            {
                arr1[i] = arr[k++];
            }

            for(int i=0;i<m;i++)
            {
                arr2[i] = arr[k++];
            }

            msort(arr1);
            msort(arr2);
            merge(arr1,arr2,arr);
        }
    }

    public static void main(String[] args)
    {
        int arr[] = {123,345,123123,34,1,2,9};
        msort(arr);

        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

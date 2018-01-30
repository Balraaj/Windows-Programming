package Sorting;

public class MergeSort
{
    static void merge(int arr1[],int arr2[],int arr[])
    {
        int n = arr1.length;
        int m = arr2.length;

        int i,j,k;
        i=j=k=0;

        while((i<n)&&(j<m))
        {
            if(arr1[i]<arr2 [j])
            {
                arr[k++]=arr1[i++];
            }
            else
            {
                arr[k++]=arr2[j++];
            }
        }

        while(i<n)
        {
            arr[k++]=arr1[i++];
        }
        while(j<m)
        {
            arr[k++]=arr2[j++];
        }
    }

    static void sort(int arr[])
    {
        int size = arr.length;
        if(size>1)
        {
            int n = size/2;
            int m = size-n;
            int k = 0;

            int[] arr1 = new int[n];
            int[] arr2 = new int[m];

            for(int i=0;i<n;i++)
            {
                arr1[i]=arr[k++];
            }

            for(int i=0;i<m;i++)
            {
                arr2[i]=arr[k++];
            }

            sort(arr1);
            sort(arr2);
            merge(arr1,arr2,arr);
        }
    }

    public static void main(String[] args) {
        int[] arr = {-3, 12, 34, 9999, -345, 2, 0,0,0, 67, 111, 122};

        System.out.println("Array before sorting : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(" " + arr[i]);
        }

        sort(arr);

        System.out.print("\n\nArray after sorting : \n\n");

        for (int i = 0; i < arr.length; i++) {
            System.out.print(" " + arr[i]);
        }
    }
}

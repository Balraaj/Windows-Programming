package Sorting;

public class SelectionSort
{
    static void sort(int arr[])
    {
        int n = arr.length;
        for(int i =0;i<n-1;i++)
        {
            int value = arr[i];
            int index = i;

            for(int j =i+1;j<n;j++)
            {
                if(arr[j]<value)
                {
                    index = j;
                }
            }

            arr[i]=arr[index];
            arr[index]=value;
        }
    }
    public static void main(String[] args)
    {
        int[] arr = new int[10000];

        for(int i=0,j=10000;i<10000;i++,j--)
        {
            arr[i]=j;
        }

        System.out.println("Array before sorting : ");
        for (int i = 0; i < 10000; i++) {
            System.out.print(" " + arr[i]);
        }

        sort(arr);

        System.out.print("\n\nArray after sorting : \n\n");

        for (int i = 0; i < 10000; i++) {
            System.out.print(" " + arr[i]);
        }
    }
}

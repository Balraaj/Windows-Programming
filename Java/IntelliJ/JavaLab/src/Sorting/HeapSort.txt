package Sorting;

public class HeapSort
{
    static void heapify(int arr[],int n,int heapsize)
    {
        int left = n*2+1;
        int right = n*2+2;
        int max = n;

        if((left<heapsize)&&(arr[left]>arr[n]))
        {
            max = left;
        }

        if((right<heapsize)&&(arr[right]>arr[max]))
        {
            max = right;
        }

        if(max!=n)
        {
            int temp = arr[n];
            arr[n] = arr[max];
            arr[max] = temp;
            heapify(arr,max,heapsize);
        }
    }

    static void sort(int arr[])
    {
        int heapsize = arr.length;
        int start = (heapsize-1)/2;

        for(int i=start;i>=0;i--)
        {
            heapify(arr,i,heapsize);
        }

        for(int i =heapsize-1;i>=1;i--)
        {
            int temp = arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapsize--;
            heapify(arr,0,heapsize);
        }
    }

    public static void main(String[] args) {
        int[] arr = {-3, 12, 34, 9999, -345, 2, 0, 67, 111, 122};

        System.out.println("Array before sorting : ");
        for (int i = 0; i < 10; i++) {
            System.out.print(" " + arr[i]);
        }

        sort(arr);

        System.out.print("\n\nArray after sorting : \n\n");

        for (int i = 0; i < 10; i++) {
            System.out.print(" " + arr[i]);
        }
    }
}

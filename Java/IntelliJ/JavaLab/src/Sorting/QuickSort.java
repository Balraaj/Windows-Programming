package Sorting;

public class QuickSort {
    static int count = 0;
  /*  static int part(int arr[], int start, int end) {
        int pivot = arr[end];
        int index = start;

        for (int i = start; i < end; i++) {
            if (arr[i] < pivot) {
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
                index++;
            }
        }

        arr[end] = arr[index];
        arr[index] = pivot;
        return index;
    }*/

    static int part(int arr[],int start,int end)
    {
        int value = arr[start];
        int i =start+1, j = end;

        while(i<j)
        {
            while((arr[i]<=value)&&(i<end))
            {
                i++;
            }

            while((arr[j]>=value)&&(j>start))
            {
                j--;
            }

            if(i<j)
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

        arr[start]=arr[j];
        arr[j]=value;
        return j;



    }
    static void sort(int arr[], int start, int end)
    {
        count++;
        System.out.print("\nsort called : "+count);
        if (start < end)
        {

            int pindex = part(arr, start, end);
            sort(arr, start, pindex - 1);
            sort(arr, pindex + 1, end);
        }
    }

    public static void main(String[] args) {
        int[] arr = {123,2,2,1,1,-123,-12,0};


        System.out.println("Array before sorting : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(" " + arr[i]);
        }

        sort(arr, 0, arr.length-1);

        System.out.print("\n\nArray after sorting : \n\n");

        for (int i = 0; i < arr.length; i++) {
            System.out.print(" " + arr[i]);
        }
    }
}
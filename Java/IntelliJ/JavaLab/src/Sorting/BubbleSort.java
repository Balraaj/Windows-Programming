package Sorting;

public class BubbleSort {

    static void sort(int arr[]) {
        int n = arr.length;
        int total = 0;

        for (int i = 1; i < n; i++)
        {
            boolean flag = true;
            for (int j = 0; j < n-1-i; j++)
            {

                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = false;
                    total++;
                }
            }

            if (flag) {
                break;
            }
        }

        System.out.println("\n\nTotal swaps : "+total+"\n\n");
    }

    public static void main(String[] args) {
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
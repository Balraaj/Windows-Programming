package Sorting;

public class InsertionSort {
    static void sort(int arr[])
    {
        int n = arr.length;

        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while ((j >= 0) && (arr[j] > key))
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
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

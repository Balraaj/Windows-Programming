package Sorting;

public class RadixSort
{
    static int[] cSort(int[] arr,int exp)
    {
        int[] B = new int[arr.length];
        int[] temp = new int[10];

        for(int i=0;i<10;i++)
        {
            temp[i] = 0;
        }

        for(int i=0;i<arr.length;i++)
        {
            temp[arr[i]/exp%10]++;
        }

        for(int i=1;i<10;i++)
        {
            temp[i] = temp[i]+temp[i-1];
        }

        for(int i=arr.length-1;i>=0;i--)
        {
            B[temp[arr[i]/exp%10]-1] = arr[i];
            temp[arr[i]/exp%10]--;
        }

        return B;
    }

    static int[] rSort(int[] arr)
    {
        int m = 0;
        int exp = 1;

        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>m)
            {
                m = arr[i];
            }
        }

        while(m/exp>0)
        {
            arr = cSort(arr,exp);
            exp*=10;
        }

        return arr;
    }


    public static void main(String[] args)
    {
        int[] arr = {23,45,89,123,4353,7,2,1,1,3,4,7};

        arr = rSort(arr);

        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

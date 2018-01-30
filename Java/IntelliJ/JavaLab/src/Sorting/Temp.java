package Sorting;

public class Temp
{
    static void sort(int[] arr)
    {
        for(int gap=arr.length/2;gap>0;gap/=2)
        {
            for(int i =gap;i<arr.length;i++)
            {
                int value = arr[i];
                int j ;
                for(j =i;(j>=gap)&&(arr[j-gap]>value);j-=gap)
                {
                    arr[j]=arr[j-gap];
                }

                arr[j]=value;
            }
        }
    }

    public static void main(String[] args)
    {
        int[] arr = {12313,3,3,3,33,3,33,123,123,34,67,23,-6,-12,-67,1,346,234,111,111};

        sort(arr);

        System.out.print("Heap is : ");
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}

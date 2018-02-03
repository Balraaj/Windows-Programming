/**
 * Created by Balraj on 02-Feb-18.
 * Given two sorted arrays print all the consecutive numbers.
 * array 1 = {1,3,5,7,9}
 * array 2 = {2,4,6,8,10}
 * print = 1,2,3,4,5,6,7,8,9,10
 */
public class ConsecutiveNumbers
{
    private static void printConsecutives(int[] arr1,int[] arr2)
    {
        int i=0;
        int j=0;
        while((i<arr1.length)&&(j<arr2.length))
        {
            int value;
            if(arr1[i]<arr2[j])
            {
                value = arr1[i++];
            }
            else
            {
                value = arr2[j++];
            }
            System.out.print(value+" ");
        }

        while(i<arr1.length)
        {
            System.out.print(arr1[i++]);
        }
        while(j<arr2.length)
        {
            System.out.print(arr2[j++]);
        }
    }

    public static void main(String[] args)
    {
        int[] arr1 = {1,3,5,6,7,9};
        int[] arr2 = {2,4,7,8,10};
        printConsecutives(arr1,arr2);
    }
}

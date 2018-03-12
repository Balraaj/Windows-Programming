/**
 * Created by Balraj on 17-Feb-18.
 * Given two sorted arrays and a value find two indices from i and j such that ABS(arr[i]+arr[j]-value) is minimum.
 * i must be from first array and j must be from the second array.
 */
public class ArrayFindPairClosestToValueInTwoArrays
{
    private static int[] findPair(int[] arr1,int[] arr2,int value)
    {
        int difference = Integer.MAX_VALUE;
        int firstIndex = 0;
        int secondIndex = 0;
        int i=0;
        int j=arr2.length-1;

        while((i<arr1.length)&&(j>=0))
        {
            int sum = arr1[i]+arr2[j];
            if(Math.abs(sum-value)<difference)
            {
                difference=Math.abs(sum-value);
                firstIndex=i;
                secondIndex=j;

                if(difference==0) return new int[]{firstIndex,secondIndex};
            }

            if(sum>value)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return new int[] {firstIndex,secondIndex};
    }

    public static void main(String[] args)
    {
        int[] arr1 = {1,3,9,15,45};
        int[] arr2 = {5,34,37,56,67};
        int[] result = findPair(arr1,arr2,600);
        System.out.println("Pair is found at : "+result[0]+" : "+result[1]);
    }
}

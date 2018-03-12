/**
 * Created by Balraj on 17-Feb-18.
 * Given an array and a value find two indices i and j such that ABS(arr[i]+arr[j]-value) is minimum.
 */
public class ArrayFindPairClosestToValue
{
    private static int[] findPair(int[] arr,int value)
    {
        int difference = Integer.MAX_VALUE;
        int firstIndex = 0;
        int secondIndex = 0;
        int i=0;
        int j=arr.length-1;

        while(i<=j)
        {
            int sum = arr[i]+arr[j];
            if(Math.abs(sum-value)<difference)
            {
                difference=Math.abs(sum-value);
                firstIndex=i;
                secondIndex=j;

                if(difference==0) return new int[]{firstIndex,secondIndex};
            }
            else if(arr[i]+arr[j]>value)
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
        int[] arr = {1,6,8,9,15,23,45};
        int[] result = findPair(arr,50);

        if(result[0]!=-1)
        {
            System.out.println("The pair is found at : "+result[0]+" and : "+result[1]);
        }
        else
        {
            System.out.print("No such pair is found");
        }
    }
}

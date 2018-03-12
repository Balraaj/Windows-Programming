/**
 * Created by Balraj on 17-Feb-18.
 * Given an array and a value find two indices i and j such that arr[i] + arr[j] = value.
 */
public class ArrayFindPairEqualToValue
{
    private static int[] findPair(int[] arr,int value)
    {
        int i=0;
        int j=arr.length-1;
        while(i<j)
        {
            if(arr[i]+arr[j]==value)
            {
                return new int[]{i,j};
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
        return new int[]{-1,-1};
    }

    public static void main(String[] args)
    {
        int[] arr = {1,3,7,9,14,17,34};
        int[] result = findPair(arr,2);
        if(result[0]!=-1)
        {
            System.out.println("Pair is found at : "+result[0]+" and : "+result[1]);
        }
        else
        {
            System.out.println("No such pair is found");
        }
    }

}

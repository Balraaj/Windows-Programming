/**
 * Created by Balraj on 09-Feb-18.
 */
public class ArrayRotate
{
    private static void reverse(int[] arr,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }

    private static void rotate(int[] arr,int amount)
    {
        reverse(arr,0,amount-1);
        reverse(arr,amount,arr.length-1);
        reverse(arr,0,arr.length-1);
    }

    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,5,6,7,8};
        rotate(arr,2);
        for(int i:arr)
            System.out.print(i+" ");
    }
}

package Searching;

public class BinarySearch
{
    static int search(int arr[],int value)
    {
        int start = 0;
        int end = arr.length-1;
        int temp = -1;

        while(start<=end)
        {
            int mid = (start+end)/2;

            if(arr[mid]==value)
            {
                temp = mid+1;
                break;
            }

            else if(arr[mid]<value)
            {
                start=mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return temp;
    }


    public static void main(String[] args)
    {
        int[] arr={-12,23,34,55,66,98};
        int position = search(arr,98);

        if(position<0)
        {
            System.out.print("Value not found");
        }
        else
        {
            System.out.print("Value found at : "+position);
        }
    }
}

package JavaTraining;

public class HeapSort
{
    private static void heapify(int[] arr,int index,int heapsize)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maximum ;

        if((left <= heapsize) && (arr[left] > arr[index]))
        {
            maximum = left;
        }
        else
        {
            maximum = index;
        }

        if((right <= heapsize) && (arr[right] > arr[maximum]))
        {
            maximum = right;
        }
        
        if(maximum!=index)
        {
            int temp = arr[index];
            arr[index] = arr[maximum];
            arr[maximum] = temp;
            
            heapify(arr,maximum,heapsize);
        }
    }

    private static void buildHeap(int[] arr)
    {
        int start = (arr.length-2)/2;
        System.out.print("arr.length-2 : "+(arr.length-2));

        System.out.print("\n\nStart is : "+start);
        for(int i=start;i>=0;i--)
        {
            heapify(arr,i,arr.length-1);
        }
    }

    private static void sort(int[] arr)
    {
        buildHeap(arr);

        System.out.print("Heap is : ");
        for(int i:arr)
        {
            System.out.print(" "+i);
        }
        int heapsize = arr.length-1;
        for(int i=arr.length-1;i>=1;i--)
        {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            heapsize-=1;

            heapify(arr,0,heapsize);
        }
    }

    public static void main(String[] args)
    {
        int[] arr={1,2,3,4,5,6,7,8};

       /* for(int i=0,j=1000000;i<1000000;i++)
        {
            arr[i] = j--;
        }*/
        sort(arr);

        System.out.println("\n");

        for(int i:arr)
        {
            System.out.print(" "+i);
        }
    }
}

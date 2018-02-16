class LIS
{
    // Binary search (note boundaries in the caller)
    // A[] is ceilIndex in the caller
    private static int CeilIndex(int A[], int l, int r, int key)
    {
        while (r - l > 1)
        {
            int m = l + (r - l)/2;
            if (A[m]>=key)
                r = m;
            else
                l = m;
        }

        return r;
    }

    private static int findIndex(int[] arr,int length,int value)
    {
        if(value<arr[0]) return 0;

        int start = 0;
        int end = length;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[mid]==value) return mid;
            else if(value>arr[mid]) start = mid+1;
            else end = mid-1;

        }
        return start;
    }

    private static int LongestIncreasingSubsequenceLength(int A[], int size)
    {
        // Add boundary case, when array size is one

        int[] tailTable   = new int[size];
        int len; // always points empty slot

        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++)
        {
            /*if (A[i] < tailTable[0])
                // new smallest value
                tailTable[0] = A[i];*/

            if (A[i] > tailTable[len-1])
                // A[i] wants to extend largest subsequence
                tailTable[len++] = A[i];

            else
                // A[i] wants to be current end candidate of an existing
                // subsequence. It will replace ceil value in tailTable
                //tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
                tailTable[findIndex(tailTable,len-1,A[i])] = A[i];
        }

        return len;
    }

    // Driver program to test above function
    public static void main(String[] args)
    {
        int A[] = { 6,1,2,3,4,-5,-3};
        int n = A.length;
        System.out.println("Length of Longest Increasing Subsequence is "+
                LongestIncreasingSubsequenceLength(A, n));
    }
}
public class MaxSumSubMatrix
{
    private static int[] maxSum(int input[][])
    {
        int maxSum=0;
        int leftBound=0;
        int rightBound=0;
        int upperBound=0;
        int lowerBound=0;
        int rows = input.length;
        int cols = input[0].length;
        int temp[] = new int[rows];

        for(int left = 0; left < cols ; left++)
        {
            for(int i=0; i < rows; i++)
            {
                temp[i] = 0;
            }
            for(int right = left; right < cols; right++)
            {
                for(int i=0; i < rows; i++)
                {
                    temp[i] += input[i][right];
                }
                int[] result = findMaxSumSubArray(temp);
                if(result[0] > maxSum)
                {
                   maxSum = result[0];
                   leftBound = left;
                   rightBound = right;
                   upperBound = result[1];
                   lowerBound = result[2];
                }
            }
        }
        return new int[] {maxSum,leftBound,rightBound,upperBound,lowerBound};
    }

    private static int[] findMaxSumSubArray(int[] arr)
    {
        int start = 0;
        int end = 0;
        int s = 0;
        int maxSoFar = arr[0];
        int maxEndingHere = 0;

        for(int i = 0; i < arr.length; i++)
        {
            maxEndingHere += arr[i];
            if(maxSoFar < maxEndingHere)
            {
                maxSoFar = maxEndingHere;
                start = s;
                end = i;
            }
            if(maxEndingHere < 0)
            {
                maxEndingHere = 0;
                s = i + 1;
            }
        }

        return new int[] {maxSoFar,start,end};
    }

    public static void main(String args[])
    {
       int input[][] =  {{ -2,  -1, -3, -4,  -5},
                         { 0,  -6,  -3,  -4,  -1},
                         { 2, -2, -1,  -4, -5},
                         {-3,  -3,  -1,  0,  3}};

       int[] result = maxSum(input);
       System.out.println("Sum is : "+result[0]);
       System.out.println("Left is : "+result[1]);
       System.out.println("Right is : "+result[2]);
       System.out.println("Upper is : "+result[3]);
       System.out.println("Lower is : "+result[4]);
    }
}

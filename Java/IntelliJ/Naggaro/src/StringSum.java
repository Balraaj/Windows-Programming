/**
 * Created by Balraj on 04-Feb-18.
 * Given a string of chars and numbers, calculate the sum of all the numbers in the string.
 * for example if string is "ab33xy44" then we have to return 77;
 */
public class StringSum
{
    private static int findSumBruteForce(char[] arr)
    {
        int sum=0;
        int i=0;
        while(i<arr.length)
        {
            int number=0;
            while((i<arr.length)&&((arr[i]<48)||(arr[i]>57)))
            {
                // keep incrementing i while char[i] is not a digit
                i++;
            }

            while((i<arr.length)&&((arr[i]>47)&&(arr[i]<58)))
            {
                number=number*10+(arr[i]-48);
                i++;
            }
            sum+=number;
        }
        return sum;
    }

    private static int findSum(char[] arr)
    {
        int sum=0;
        int number=0;
        int i=0;
        while(i<arr.length)
        {
            if((arr[i]>47)&&(arr[i]<58)) // if current char is a digit then add it to number
            {
                number=number*10+(arr[i]-48);
            }
            else
            {
                sum+=number; // if current char is not a digit then it means we have reached end of a number
                number=0;   //  hence add that number to the sum and set the number to 0. this step doesn't
                           //   happen if there is a number in the end for example ab55xy44. in this example
                          //    44 is successfully scanned but can't be added to sum because a non digit char was
                         //     was not encountered.
            }
            i++;
        }
        sum+=number;    // if number was at the end of string
        return sum;
    }

    public static void main(String[] args)
    {
        String numbers = "5";
        System.out.println("Sum is "+findSum(numbers.toCharArray()));
    }
}

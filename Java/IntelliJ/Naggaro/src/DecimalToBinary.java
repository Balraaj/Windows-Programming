/**
 * Created by Balraj on 03-Feb-18.
 * Given a decimal representation convert it to equivalent binary representation.
 */
public class DecimalToBinary
{
    private static long toBinaryBitManipulation(int decimal)
    {
        long binary=0;
        int digitsCount=0;
        int i=0;
        while(i<32)
        {
            if(((decimal>>i)&(1))==1) // shift right by one position check LSB by ANDing with 1
            {
                binary=(long)Math.pow(10,digitsCount)+binary; // if LSB is 1 then update the variable
            }
            digitsCount++;
            i++;
        }

        return binary;
    }

    private static boolean toBinaryCheckPalindrome(int decimal)
    {
        long binary=0;
        int i=0;
        while(i<32)
        {
            if(((decimal>>i)&(1))==1)
            {
                binary=(long)Math.pow(10,i)+binary;
            }
            i++;
        }

        System.out.println("Binary is : "+binary);
        String str = String.valueOf(binary);
        int j=0;
        int k=str.length()-1;
        while(j<k)
        {
            if(str.charAt(j)!=str.charAt(k))
            {
                return false;
            }
            else
            {
                j++;
                k--;
            }
        }

        return true;
    }

    private static long toBinary(int decimal)
    {
        int digitsCount=0;
        long binary=0;
        while(decimal>=1)
        {
            int digit=decimal%2;
            if(digit==1)
            {
                binary+=(long)Math.pow(10,digitsCount);
            }
            digitsCount++;
            decimal/=2;
        }
        return binary;
    }
    public static void main(String[] args)
    {
        int decimal = 4097;
        System.out.println(decimal+" in binary is : "+toBinary(decimal));
    }
}

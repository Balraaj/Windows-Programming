/**
 * Created by Balraj on 28-Jan-18.
 *
 * This program finds if a given string is permutation of a palindrom (CTCI 4)
 */
public class PalindromPermutation
{
    private static boolean chekcPalindromPermutation(String str)
    {
        int count = 0;
        // Bit map to save space. because we are only considering strings with english alphabet
        for(int i=0;i<str.length();i++)
        {
            int c = (int)str.charAt(i);
            if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122)))
            {
                if((c>=65)&&(c<=90))
                {
                    c-='A';
                }
                else
                {
                    c-='a';
                }

                /* Because we only need to check if every character occurs even no. of times or odd no. of times
                   so we XOR the contents of the count with the value of character which flips the respective bit.
                   if the bit was 0 then it becomes 1 and vice versa.
                 */
                count = count^(1<<c);
            }
        }
        return ((count==0)||(count&(count-1))==0);
    }

    public static void main(String[] args)
    {
        boolean flag = chekcPalindromPermutation("thissihtathissiht");
        System.out.println("String is permutation of palindrom : "+flag);
    }
}

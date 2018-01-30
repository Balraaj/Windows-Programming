/**
 * Created by Balraj on 29-Jan-18.
 *
 * Given a string perform a simple run length encoding. if string cant be compressed return the original string.
 * (CTCI 6)
 */
public class StringCompress
{
    private static String compressString(String str)
    {
        StringBuilder newStr = new StringBuilder();
        int count;
        int reduction=0;
        for(int i=0;i<str.length();i++)
        {
            char currentChar=str.charAt(i);
            count=1;
            while((i<str.length()-1)&&(str.charAt(i+1)==currentChar))
            {
                count++;
                i++;
            }

            reduction+=count-2;
            newStr.append(currentChar);
            newStr.append(count);
        }

        if(reduction>0)
        {
            return newStr.toString();
        }
        return str;
    }

    public static void main(String[] args)
    {
        String str = "aabbcxyzcdddddddddddddddd";
        System.out.print("Compressed form of "+str+" is : "+compressString(str));
    }
}

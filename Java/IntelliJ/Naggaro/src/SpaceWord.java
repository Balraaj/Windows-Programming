/**
 * Created by Balraj on 05-Feb-18.
 * Given a string of words determine the length of each word, if its greater than four and is even
 * then print a space in middle of the word. other wise print the word as it is.
 */
public class SpaceWord
{
    private static void printSpaceWord(char[] arr)
    {
        int i=0;
        while(i<arr.length)
        {
            int j=i;
            while((j<arr.length)&&(arr[j]!=' ')&&(arr[j]!='\n')) // keep going until blanc space is encountered.
            {
                j++;
            }
            int length=j-i;
            int spaceIndex=-1;

            if((length>4)&&(length%2==0)) // if length is within bounds then set the space index.
            {
                spaceIndex=length/2;
            }

            while((i<arr.length)&&(i<=j))
            {
                if(spaceIndex==0)
                {
                    System.out.print(" ");
                    spaceIndex--;
                }
                else
                {
                    System.out.print(arr[i++]);
                    spaceIndex--;
                }
            }
        }
    }

    public static void main(String[] args)
    {
        String str = "hello this is whoand what career and abcdefghijkl mnopqr stuvwx\nheelow";
        printSpaceWord(str.toCharArray());
    }
}

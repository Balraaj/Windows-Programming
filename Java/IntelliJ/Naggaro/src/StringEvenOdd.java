/**
 * Created by Balraj on 09-Feb-18.
 * Given a String of 1's and 0's rearrange it so that 1's occur at odd places and 0's at even places.
 */
class StringEvenOdd
{
    public static void main(String[] args)
    {
        StringBuilder str = new StringBuilder("00010101000");
        rearrangeString(str);
        System.out.println(str);

    }

    private static void rearrangeString(StringBuilder str)
    {
        int count=0;
        int length = str.length();
        char[] arr = str.toString().toCharArray();
        for(char c:arr)
        {
            if(c=='1')
            {
                count++;
            }
        }

        str.setLength(0);
        for(int i=0;i<length;i++)
        {
            if((i%2==1)&&(count>0))
            {
                str.append(1);
                count--;
            }
            else
            {
                str.append(0);
            }
        }
    }
}

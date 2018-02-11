/**
 * Created by Balraj on 09-Feb-18.
 * Given a string of english alphabets determine if it contains all the letters.
 */
public class PanagramString
{
    private static boolean checkPanagram(String str)
    {
        int count=0;
        for(int i=0;i<str.length();i++)
        {
            int c = str.charAt(i);
            c=c|' '; // or with space changes to lower case.
            c-='a';
            count = count|(1<<c);
            if(count==0x03ffffff)
            {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        String str = "AbcdefghijklmnopqrstuvwxyzZ";
        System.out.println("String is panagram : "+checkPanagram(str));
    }
}

/**
 * Created by Balraj on 28-Jan-18.
 *
 * Given two strings check if they are one edit away. (CTCI)
 */
public class OneAway
{
    private static boolean checkOneAway(String str1, String str2)
    {
        if(str1.length()==str2.length())
        {
            return checkOneReplace(str1,str2);
        }
        else if(str1.length()+1==str2.length())
        {
            return checkOneReplace(str2,str1);
        }
        else if(str1.length()-1==str2.length())
        {
            return checkOneReplace(str1,str2);
        }

        return false;
    }

    private static boolean checkOneReplace(String large,String small)
    {
        boolean flag=false;
        for(int i=0,j=0;j<small.length();i++,j++)
        {
            if(large.charAt(i)!=small.charAt(j))
            {
                if(flag)
                {
                    return false;
                }
                else
                {
                    flag=true;
                    /*
                    Following if is added to handle the insert case (when lengts are not equal).
                    once we find a character mismatch we increment the index of larger array.
                    but index of smaller array must stay the same.
                    that is why j is decremented to keep it same.
                     */
                    if(large.length()>small.length())
                    {
                        j--;
                    }
                }
            }
        }

        return true;
    }

    /*
    We don't need this method as checkOneReplace can handle this case also with little modification.
     */

    private static boolean checkOneInsert(String large,String small)
    {
        boolean flag = false;
        for(int i=0,j=0;j<small.length();i++,j++)
        {
            if(large.charAt(i)!=small.charAt(j))
            {
                if(flag)
                {
                    return false;
                }
                else
                {
                    flag=true;
                }
            }
        }

        return true;
    }

    public static void main(String[] args)
    {
        boolean result = checkOneAway("balraj","barraj");
        System.out.print("String are one edit away : "+result);
    }
}

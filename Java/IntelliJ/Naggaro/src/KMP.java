/**
 * Created by Balraj on 04-Feb-18.
 */
public class KMP
{
    private static int[] calculatePrefix(String pattern)
    {
        /*
            Prefix[k] gives the length of longest suffix which is also a prefix in substring(0,k-1).
            Another way to look at it is to take prefix[k] as length of longest suffix which is
            also a prefix when k characters have successfully matched.
            yet another way is that prefix[k] gives the index that must be compared next when mismatch
            occurred at index k+1;
         */
        int[] prefix = new int[pattern.length()];
        prefix[0]=0;
        int i=1;
        int k=0;
        while(i<pattern.length())
        {
            char c = pattern.charAt(i);
            while((k>0)&&(c!=pattern.charAt(k)))
            {
                k = prefix[k-1];
            }

            if(c==pattern.charAt(k))
            {
                k++;
            }
            prefix[i++]=k;
        }
        return prefix;
    }

    private static void  KMPMatcher(String text,String pattern)
    {
        int[] prefix = calculatePrefix(pattern);
        int i=0;
        int k=0;
        while(i<text.length())
        {
            char c = text.charAt(i);
            while((k>0)&&(c!=pattern.charAt(k)))  // Here we are matching ith text char with (k+1)th pattern char
            {                                    //  because indices start from 0

                k = prefix[k-1];
            }

            if(c==pattern.charAt(k))
            {
                k++;    // for every matched character k is incremented, hence k stores the no. of matched chars.
            }

            if(k==pattern.length())
            {
                System.out.println("Pattern occurs at : "+(i-pattern.length()+1));
                k=prefix[k-1];
            }
            i++;
        }

    }

    public static void main(String[] args)
    {
        String text = "Hello my name is balraj and who are you Hello my name is balraj and who are you " +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are you" +
                "Hello my name is balraj and who are you Hello my name is balraj and who are youhis";
        System.out.println("Length of string is : "+text.length());
        String pattern = "his";
        KMPMatcher(text,pattern);
    }
}

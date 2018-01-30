/*
Given two strings check if one is permutation of another.
 */

class FindPermutation
{
    private static boolean checkPermutation(String text, String perm)
    {
        int[] arr = new int[26];
        int count=0;
        for(int i=0;i<perm.length();i++)
        {
            char c = perm.charAt(i);
            int temp=c-97;
            arr[temp]++;
        }

        for(int i=0;i<text.length();i++)
        {
            int index = text.charAt(i)-97;
            if(arr[index]==0)
            {
                break;
            }
            else
            {
                arr[index]--;
                count++;
            }
        }

        return (count==perm.length());
    }

    public static void main(String[] args)
    {
        String text = "abdecaena";
        String perm = "aabcdenea";
        System.out.print("Its a permutation : "+checkPermutation(text,perm));
    }
}
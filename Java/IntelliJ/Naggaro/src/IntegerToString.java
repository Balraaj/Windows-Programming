/**
 * Created by Balraj on 03-Feb-18.
 * Given an integer convert it to String.
 */
public class IntegerToString
{
    private static String convert(int number)
    {
        StringBuilder str = new StringBuilder();
        while(number>=1)
        {
            int digit = number%10;
            str.append((char)(digit+48));
            number=number/10;
        }

        return str.reverse().toString();
    }

    public static void main(String[] args)
    {
        int number = 12341;
        System.out.print(convert(number));
    }
}

package Java;

/**
 * Created by Balraj on 12-Mar-18.
 */
public class TypePromotion
{
    private static void myMethod(double value)
    {
        System.out.println("value is : "+value);
    }
    public static void main(String[] args)
    {
        char c = 'a';
        myMethod(c);
        byte b = 127;
        b++;
        System.out.println(Integer.toBinaryString(b));
        b=(byte)(b>>>1);
        System.out.println(Integer.toBinaryString(b));
        System.out.println(b);
        double d = 1.0/6.0;
        d=d*6;
        System.out.println(d);
    }
}

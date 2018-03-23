package Java;

/**
 * Created by Balraj on 12-Mar-18.
 */

interface myInterface
{
    int var=10;
    void myMethod();
}
class myClass
{
    public void myMethod()
    {
        System.out.println("This method is defined inside class");
    }
    public static void staticMethod()
    {
        System.out.print("\nThis is static method");
    }
}
public class InterfaceDemo extends myClass implements myInterface
{
    public static void main(String[] args)
    {
        new InterfaceDemo().myMethod();
    }
}

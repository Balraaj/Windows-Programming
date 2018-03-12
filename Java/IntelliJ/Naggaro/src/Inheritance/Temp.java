package Inheritance;

/**
 * Created by Balraj on 01-Mar-18.
 */
public class Temp
{
    public void print()
    {
        System.out.println("This is Parent class");
    }
}

class Temp1 extends Temp
{
    public void printChild()
    {
        System.out.println("This is child class");
    }

    public void callThePrint()
    {
        print();
        super.print();
    }

    public static void main(String[] args)
    {
        Temp1 obj = new Temp1();
        obj.callThePrint();
    }
}

/**
 * Created by Balraj on 29-Jan-18.
 */
public class Temp
{

    public static void main(String[] args)
    {
        StringBuilder str = new StringBuilder();
        System.out.println("Current Capacity is : "+str.capacity());
        str.append("hello who are you");
        System.out.println("Current Capacity is : "+str.capacity());
        char c = 'A';
        c++;
        System.out.println("c is : "+c);



        String A = new String("Hello");
        String B = new String("Hello");
        String C = "Hello";
        if(A==B)
        {
            System.out.println("A and B point to same thing ");
        }

        if(A.equals(B))
        {
            System.out.println("A and B contain the same string");
        }

        String D = "Hello";
        System.out.println("C and D point to same memory : "+(C==D));
    }
}

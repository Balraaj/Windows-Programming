/**
 * Created by Balraj on 23-08-2016.
 */
interface a
{
    int i=10;
}

interface b
{
    int i =20;
}

public class inter implements a,b
{
    public static void main(String[] args)
    {
        System.out.println(a.i);
    }
}

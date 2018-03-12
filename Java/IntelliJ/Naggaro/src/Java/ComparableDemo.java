package Java;

import java.util.Arrays;

/**
 * Created by Balraj on 08-Mar-18.
 */
public class ComparableDemo implements Comparable<ComparableDemo>
{
    private String name;

    ComparableDemo(String name)
    {
        this.name=name;
    }

    @Override
    public int compareTo(ComparableDemo o)
    {
        String first = this.name;
        String second = o.name;

        return first.compareTo(second);
    }

    public static void main(String[] args)
    {
        ComparableDemo[] arr = new ComparableDemo[5];
        arr[0]=new ComparableDemo("Amit");
        arr[1]=new ComparableDemo("Rajiv");
        arr[2]=new ComparableDemo("Sumit");
        arr[3]=new ComparableDemo("Ketan");
        arr[4]=new ComparableDemo("Zorro");

        Arrays.sort(arr);
        for(int i=0;i<5;i++)
        {
            System.out.println(arr[i].name);
        }
    }
}

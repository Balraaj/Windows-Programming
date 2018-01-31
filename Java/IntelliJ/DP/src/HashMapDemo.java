import java.util.HashMap;

/**
 * Created by Balraj on 31-Jan-18.
 */
public class HashMapDemo
{
    public static void main(String[] args)
    {
        HashMap<Integer,String> myMap = new HashMap<>();
        myMap.put(1,"Balraj");
        myMap.put(2,"Brar");
        myMap.put(3,"Hello");

        System.out.println("Values in the map are : "+myMap.values());

    }
}

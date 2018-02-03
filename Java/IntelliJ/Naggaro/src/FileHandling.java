import java.io.BufferedReader;
import java.io.FileReader;

/**
 * Created by Balraj on 03-Feb-18.
 */
public class FileHandling
{
    public static void main(String[] args)
    {
        try
        {
            BufferedReader br = new BufferedReader(new FileReader("myfile"));
            String str;
            while((str=br.readLine()) != null)
            {
                System.out.println(str);
            }
        }
        catch(Exception e)
        {
            System.out.print(e);
        }
    }
}

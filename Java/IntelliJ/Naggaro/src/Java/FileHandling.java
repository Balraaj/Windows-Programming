package Java;

import java.io.*;

/**
 * Created by Balraj on 08-Mar-18.
 */
public class FileHandling
{
    public static void main(String[] args)
    {

        try
        {
            BufferedReader br = new BufferedReader(new FileReader("myfile.txt"));
            //BufferedWriter bw = new BufferedWriter(new FileWriter("myfile.txt"));

            String line;
            while((line=br.readLine())!=null)
            {
                System.out.println(line);
            }

            String[] arr = new String[1];
            main(arr);

        } catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

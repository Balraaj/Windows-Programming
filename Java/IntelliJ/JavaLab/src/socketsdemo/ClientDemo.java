package socketsdemo;

import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class ClientDemo
{
    public static void main(String[] args)
    {
        try
        {
            Socket socket = new Socket(InetAddress.getLoopbackAddress(), 9090);
            Scanner in = new Scanner(System.in);
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            while(true)
            {
                System.out.print("I am listening : ");
                String inputLine = in.nextLine();

                System.out.println("Writing to socket");
                out.println(inputLine);
                out.flush();
                if(inputLine.equals(""))
                {

                    break;
                }
            }
        }
        catch (Exception e)
        {
            System.out.println("This is an exception "+e);
        }
    }
}

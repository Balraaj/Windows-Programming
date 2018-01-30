package socketsdemo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerDemo
{
    public static void main(String[] args)
    {
        try
        {
            ServerSocket serverSocket = new ServerSocket(9090,0, InetAddress.getLoopbackAddress());
            Socket clientSocket = serverSocket.accept();
            System.out.println("Got a connection");
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String inputLine;
            System.out.println("I am entering the loop");
            while((inputLine=in.readLine())!=null)
            {
                System.out.println("Client says : "+inputLine);
                if(inputLine.equals(""))
                {
                    break;
                }
            }
            System.out.println("I am out of loop");

        }

        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}

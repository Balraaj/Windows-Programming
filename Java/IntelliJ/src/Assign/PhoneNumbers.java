package Assign;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class PhoneNumbers {

    public StringBuilder s;
    public void create_file()
    {
        FileWriter fw = null;
        try
        {
            fw = new FileWriter("telephone_index.txt");
        }
        catch (Exception e)
        {
            System.out.print("File is not open");
        }

        Scanner in = new Scanner(System.in);
        System.out.print("How many no. you want to enter : ");
        int n=in.nextInt();

        String mystring;

        for (int i = 0; i < n; i++)
        {
            System.out.print("Enter phone no : ");
            mystring = in.next() + ':';

            try
            {
                fw.write(mystring);
                fw.flush();
            }
            catch (Exception e)
            {
                System.out.print("Can not write to file");
            }

        }
    }

    public void findnumbers()
    {
        s = new StringBuilder();
        Scanner in=null;
        String mystring;

        //reading file
        try
        {
            in = new Scanner(new FileReader("telephone_index.txt"));
            in.useDelimiter(":");
        }
        catch(Exception e)
        {
            System.out.print("Got it");
        }

        while(in.hasNext())
        {
            mystring=in.next();
            int l=mystring.length();

            int arr[]=new int[l];
            l--;
            int temp=Integer.parseInt(mystring);

            while(l>=0)
            {
                int a =temp%10;
                temp=temp/10;
                arr[l--]=a;
            }
            if((arr[0]==4)&&(arr[1]==1)&&(arr[2]==6))
            {
                s.append(mystring);
                s.append(',');
            }
        }

        if(s.length()>0)
        {
            s.deleteCharAt(s.length()-1);
        }

    }

    public void printnumbers()
    {
        System.out.println("All the numbers that start with 416 are : ");
        System.out.print(s);
    }
}

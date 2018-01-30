package exceptions;
import java.util.*;
public class Test
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int z = 0 ;
		   
		while(true)
		{
			try
			{
				System.out.print("\nEnter the value = ");
				z = in.nextInt();
				break;
			}
			catch(Exception e)
			{
				System.out.println("Sorry it is wrong input , Please Enter a no.\n");
				in.next();
			}
		}
		System.out.print("\n Value of Variable is = "+z);
		in.close();
	}
	
	
}
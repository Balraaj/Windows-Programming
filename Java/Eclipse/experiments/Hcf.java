package experiments;
import java.util.*;

public class Hcf 
{
	public static void main (String [] args)
	{
		Scanner in = new Scanner(System.in);
		int a, b;
		while(true)
		{
			try
			{
				System.out.print("\nEnter first no. = ");
				a =  in.nextInt();
				break;
			}
			
			
			catch(Exception e)
			{
				System.out.print("\nSorry,Please Enter a no.");
				in.next();
				
			}
		}
		
		while(true)
		{
			try
			{
				
			
				System.out.print("\nEnter second no. = ");
				b = in.nextInt();
				break;
			}
			
			catch(Exception e)
			{
				System.out.print("\nSorry,please enter a no.");
				in.next();
			}
		}
		
		System.out.print("\n\nH.C.F. = "+gcd(a,b));
		in.close();
		
	}
	
	public static int gcd(int x, int y)
	{
		if (x%y==0)
			return y;
		else 
			return gcd(y,x%y);
	}

}

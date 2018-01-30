package experiments;
import java.util.*;

public class Final {

	public static void main(String[] args) 
	
	{
		Scanner in = new Scanner(System.in);
		int a = 10;
		int b ;
		System.out.print("Enter value of B = ");
		b = in.nextInt();
		try
		{
		
			try
		      
			{
				int c = a/b;
				System.out.println("Value of C = "+c);
				
			}
			catch(Exception e)
			{
				System.out.println("This operation can not be performed");
				int d = a/b;
				System.out.println("Value of d = "+d);
			}
			finally
			{
				System.out.println("This is the code that will always run");
				int z =a/b;
				System.out.println("Hello , Value of z = "+z);
			}
		}
			catch(Exception e)
			
		     {
				System.out.println("Exception is caught in outer catch ");
				
			    e.printStackTrace();
		     }
	      
	      
		    
		
		      
		in.close();

	}

}

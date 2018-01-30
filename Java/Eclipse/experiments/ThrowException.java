package experiments;

public class ThrowException 
{
	public static void main(String [] args)
	{
		int a = 10;
		int b = 2;
		try
		{
			try
		
		{
			int c = a/b;
			if(b==2)
				throw new BalrajException("Hello I am a custom exception");
			//throw new BalrajException();
		    System.out.println("Value of c = "+c);
			
			
		}
		catch(BalrajException z)
		{
			
			z.printStackTrace();
			throw new BalrajException("Hello i am custom exception no. 2");
		}
		}
		catch(BalrajException x)
		{
			x.printStackTrace();
		}
		
		
	}

}

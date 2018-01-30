package experiments;

@SuppressWarnings("serial")
public class BalrajException extends Throwable
{
	
	String m;
	BalrajException(String k)
	{
		m=k;
	}
	
	public String toString()
	{
		return m;
	}

}

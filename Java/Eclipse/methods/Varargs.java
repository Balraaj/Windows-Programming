package methods;

public class Varargs 
{
	public  String toString()	
	{
		return "This Class is used to explain working of a varargs method";
	}
	static void show(int...v)
	{
		int sum=0;
		int a=v.length;
		for(int i = 0;i<v.length;i++)
		{
			sum+=v[i];
		}
		
		System.out.println("Average is = "+sum/a);
	}
	
	public static void main(String [] args)
	{
		Varargs z = new Varargs();
		System.out.println(z);
		show(12,20,4);
		show(14,14,60,12);
	}

}

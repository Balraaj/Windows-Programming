package inheritance;

public class GrandChild extends Child
{
	int z;
	GrandChild()	
	{
		//System.out.println("Constructer of GrandChild");
		z= 40;
		
		
	}
	
	void show()
	{
		
		a=1;
		b=2;
		System.out.println("Value of z = "+z);
		super.show();
	}

}

package inheritance;

public class Child extends Parent 

{
	int k;
	
	
	
	Child()
	{
		
	//	System.out.println("Constructer of child");
		
		k=30;
		
	}
	
	void show()
	{
		a=3;
		b=4;
	    
		System.out.println("Value of k = "+k);
		super.show();
	}

}

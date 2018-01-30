package inheritance;

public class Check 

{
	public static void main(String [] args)
	{
		
	   Parent m = new Parent();
	   System.out.println("\nShow called from Parent \n\n");
	   m.show();
	   
	   Child n = new Child();
	   System.out.println("\nShow called from Child \n\n");
	   n.show();
      GrandChild a = new GrandChild();
      System.out.println("\nShow called from GrandCHild \n\n");
      
      a.show();
      
       
       
	}
}

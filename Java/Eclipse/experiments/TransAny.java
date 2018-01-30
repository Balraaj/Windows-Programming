
package experiments;
import java.util.*;
public class TransAny 
{
  public static void main(String [] args)
  {
	  Scanner in = new Scanner (System.in);
	  int a, b;
	  
	   a= take1(in);
	   
	   
	   b= take2(in);
	   
	   int x[][]= new int[a][b];
	   int y[][]= new int[b][a];
	   int k=1;
	  
	   System.out.println("Enter data :\n\n");
	   for(int i=0;i<a;i++)
	   {
		   for(int j=0;j<b;j++)
		   {
			   try
			   {
				   System.out.print("Enter element "+k+" = ");
				   x[i][j]=y[j][i]=in.nextInt();
				   k++;
			   }
			   catch(Exception e)
			   {
				   System.out.println("Sorry, please enter a no.");
				   in.next();
				   j--;
			   }
		   }
	   }
	  
	 
	  
	  System.out.println("This is how your matrix look\n\n");
	  
	  
	  for(int i =0;i<a;i++)
	  {
		  for(int j=0;j<b;j++)
		  {
			  System.out.print("     "+x[i][j]);
		  }
		  System.out.println();
	  }
	  
	  System.out.println("\n\n\nThis is how transpose looks \n\n");
	  
	  for(int i=0;i<b;i++)
	  {
		  for(int j=0;j<a;j++)
		  {
			  System.out.print("     "+y[i][j]);
			  
		  }
		  
		  System.out.println();
	  }
	  
	  
	 in.close(); 
	  
	  
	  
  }
  
  
			  public static int take1(Scanner z)
			  {
				  
				  while(true)
				  {
					  try
					  {
						  System.out.print("\nHow many rows you want = ");
						  return z.nextInt();
					  }
					  catch(Exception e )
					  {
						  System.out.println("Sorry,Please enter only no.");
						  z.next();
					  }
					  
				  }
				  
			  }
  
  public static int take2(Scanner z)
  {
	  
	  while(true)
	  {
		  try
		  {
			  System.out.print("\nHow many coloms you want = ");
			  return z.nextInt();
		  }
		  catch(Exception e )
		  {
			  System.out.println("Sorry,Please enter only no.");
			  z.next();
		  }
	  }
	  
	
	  
	  
	
  }
}
 
	
	


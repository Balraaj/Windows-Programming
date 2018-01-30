package experiments;
import java.util.*;
public class ForEach 
{
  public static void main (String [] args)
  {
	  Scanner in = new Scanner(System.in);
	  int a[]= new int [5];
	  for(int i=0;i<5;i++)
	  {
		  System.out.print("\nEnter element "+(i+1)+" = ");
		  
		  try
	         {
			  a[i]=in.nextInt();
	         }
		  catch(Exception e)
		  {
			  System.out.println("\nSorry Please enter a no.");
			  i--;
		  }
		  
	  }
	  
	  int sum=0;
	  
	  
	  for(int z:a)
		  sum+=z;
		
	  int avg =  sum/5;
	  
	  System.out.println("Avg is = "+avg);
	  in.close();
  }
	
	
}

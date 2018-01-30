package experiments;
import java.util.*;
public class Transpose 
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int a[][] = new int [3][3];
		System.out.println("Enter eliments of Matrix");
		
		int k=1;
		
		
		for(int i=0; i<3;i++)
		{
			
			
			for( int j =0; j<3;j++)
			{
				try
				{
					System.out.print("Enter element "+k+" = ");
					a[i][j]=in.nextInt();
					k++;
				}
				
				catch(Exception e )
				{
					System.out.println("Please enter only no.");
					j--;
					
					in.next();
				}
			}
		
		
		}
		
		int b[][]= new int[3][3];
		
		System.out.println("Your matrix looks like this:::");
		
		for(int i =0;i<3;i++)
		{
			
			for(int j =0;j<3;j++)
			{
				System.out.print("    "+a[i][j]);
				
			}
			
			
			System.out.println();
		}
		
		System.out.println("\n\nThis is how transpose looks:::");
		
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				b[i][j]=a[j][i];
				System.out.print("      "+b[i][j]);
			}
			
			
			System.out.println();
		}
		
		 in.close();
	}
}

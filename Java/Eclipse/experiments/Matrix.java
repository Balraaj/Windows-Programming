package experiments;
import java.util.*;
public class Matrix
{
	public static void main(String [] args)
	{
		System.out.println("\n\nHello Mr. "+args[0]);
		Scanner in = new Scanner(System.in);
		int  a[][] = new int [3][2] ;
		int  b[][] = new int [2][3];	
		
		System.out.println("Enter the eliments of matrix");
		
		for (int i = 0; i < 3; i++) 
		
		{
			for (int j = 0; j < 2; j++) 
			{
				try
				{
					System.out.print("\nEnter eliment = ");
					a[i][j]=in.nextInt();
				}
				catch(Exception e)
				{
					System.out.println("Please enter a no.");
					j--;
					in.next();
				}
				
				
			}
			
		}
		
		System.out.println("Your matrix looks like this::");

		for (int i = 0; i < 3; i++) 
		
		{
		
			for (int j = 0; j < 2; j++) 
			{
				
				System.out.print("  "+a[i][j]);
				b[j][i]=a[i][j];
				//System.out.print("             "+b[j][i]);
				
			}
			
			
			
			System.out.println();
		}
		System.out.println("\n\nTranspose looks like this");
		
		for(int i=0;i<2;i++)
		{
			for(int j = 0;j<3;j++)
			{
				System.out.print("  "+b[i][j]);
			}
			System.out.println();
		}
		
		in.close();
		
	}
}

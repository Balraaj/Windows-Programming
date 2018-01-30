package experiments;
import java.util.*;
public class Trans {
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int a[][]= new int [3][3];
		int b[][]= new int [3][3];
		
		
		System.out.println("Enter elements of your matrix");
		
		int k =1;
		for(int i = 0 ;i<3;i++)
		{
			for(int j =0;j<3;j++)
			{
				try
				{
					System.out.print("Enter elements "+k+" = ");
					b[j][i]=a[i][j]=in.nextInt();
					k++;
					
				}
				catch(Exception e)
				{
					System.out.println("sorry,please enter a no.");
					in.next();
					j--;
				}
				
			}
		}
		
		
		System.out.println("Here is how your matrix looks ::");
		
		for(int i =0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print("    "+a[i][j]);
			}
			
			System.out.print("    ");
			
			for(int z=0;z<3;z++)
			{
				System.out.print("     "+b[i][z]);
			}
			
			System.out.println();
		}
		
		in.close();
	}

}

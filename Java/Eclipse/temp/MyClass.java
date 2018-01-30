package temp;

class Complex
{
	double real,img;
	Complex(double r,double i)
	{
		real = r;
		img = i;
	}
	
	Complex(Complex ob)
	{
		real = ob.real;
		img = ob.img;
	}
	
	public String toString()
	{
		String temp;
		temp = real+"+"+img+"i";
		return temp;
	}
}

public class MyClass 
{
	public static void main(String[] args)
	{
		Complex c1 = new Complex(12, 23);
		System.out.println("c1 is : "+c1);
		Complex c2 = new Complex(c1);
		System.out.print("\nc2 is : "+c2);
	}

}

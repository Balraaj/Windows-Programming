using System;

namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            int x = 0;
            int y = 0;
            int n = 0;
            int result = 0;

            Console.WriteLine("--------  MENU ---------");
            Console.WriteLine("1: Addition");
            Console.WriteLine("2: Subtraction");
            Console.WriteLine("3: Multiplication");
            Console.WriteLine("4: Division");

            Console.Write("\nEnter your choice : ");
            n = Convert.ToInt32(Console.ReadLine());

            Console.Write("\nEnter first no : ");
            x = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter second no : ");
            y = Convert.ToInt32(Console.ReadLine());

            switch(n)
            {
                case 1:
                    result = x + y;
                    break;
                case 2:
                    result = x - y;
                    break;
                case 3:
                    result = x * y;
                    break;
                case 4:
                    try
                    {
                        result = x / y;
                    }
                    catch(ArithmeticException e)
                    {
                        Console.WriteLine("\nCan not divide by zero");
                        result = 0;
                    }
                    break;                    
            }

            Console.WriteLine("Result : " + result);
            Console.Read();
            
        }
    }
}

using System;

namespace MyProject
{
    class ExtP1
    {
        static void Main(String[] args)
        {
            if (args.Length > 0)
            {
                Console.WriteLine("Argument is : "+args[0]);
            }
            Console.WriteLine("Value of 100 is : "+ 100.ToString());
            
        }
    }
}

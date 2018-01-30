using System;

namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            string str1;
            string str2;
            int pos = 0;

            Console.Write("Enter first string  : ");
            str1 = Console.ReadLine();
            Console.Write("Enter second string : ");
            str2 = Console.ReadLine();

            pos = str1.CompareTo(str2);

            Console.WriteLine("\nComparison : ");
            if(pos==0)
            {
                Console.WriteLine("\nBoth strings are same");
            }
            else if(pos<0)
            {
                Console.WriteLine("String 1 comes before String 2");
            }
            else if (pos > 0)
            {
                Console.WriteLine("String 2 comes before String 1");
            }

            Console.WriteLine("\nChange case : ");
            Console.WriteLine("String 1 in upper case : " + str1.ToUpper());
            Console.WriteLine("String 2 in upper case : " + str2.ToUpper());

            str1 = String.Concat(str1, str2);

            Console.WriteLine("\nConcatinated String is : " + str1);

            Console.Read();

        }
    }
}

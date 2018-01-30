using System;

namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            int[] arr = { 3, 29, 5, 17, 11, 13, 7, 19, 23, 2 };

            Console.Write("\nArray  : ");
            foreach (int x in arr)
                Console.Write(x+" ");

            Console.WriteLine("\n\nLength of array  : " + arr.Length);            

            Console.WriteLine("Rank of array  : " + arr.Rank);

            Array.Sort(arr);
            Console.Write("Sorted array  : ");
            foreach (int x in arr)
                Console.Write(x + " ");

            Array.Reverse(arr);

            Console.Write("\nReverse of array  : ");
            foreach (int x in arr)
                Console.Write(x + " ");

            Console.Read();
            
        }
        
    }
}

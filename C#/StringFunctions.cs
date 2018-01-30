using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class StringFunctions
    {
        public static void Main(string[] args)
        {
            
            /*string s1 = "Hello";
            string s2 = "Hello";
            StringBuilder s3 = new StringBuilder("Hello");
            int i = string.Compare(s1, s2);

            char[] arr = s2.ToCharArray();
            Array.Reverse(arr);
            s2 = new string(arr);

            Console.WriteLine("s1 : " + s1);
            Console.WriteLine("s2 : " + s2);

            if(i==0)
            {
                Console.WriteLine("Strings are equal");
            }*/

            int[] arr = new int[10];

            for(int i =0;i<10;i++)
            {
                arr[i] = i;
            }

            Array.Reverse(arr);

            for (int i = 0; i < 10; i++)
            {
                Console.Write("  " + arr[i]);
            }

            Array.Reverse(arr);

            Console.WriteLine();
            for(int i =0;i<10;i++)
            {
                Console.Write("  " + arr[i]);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class ArrayReverse
    {
        public static void Main(string[] args)
        {
            string[] arr = { "Delhi", "Mumbai", "Goa", "Jaipur", "Chandigarh" };

            for(int i=0;i<arr.Length;i++)
            {
                char[] carr = arr[i].ToCharArray();
                Array.Reverse(carr);
                arr[i] = new string(carr);
            }

            foreach (string s in arr)
                Console.WriteLine(s);
        }
    }
}

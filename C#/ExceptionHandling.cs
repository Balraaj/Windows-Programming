using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class ExceptionHandling
    {
        public static void Main(string[] args)
        {
            int a = 10;
            int b = 0;
            int[] arr = new int[5];
            try
            {
                //int c = a / b;
               // Console.WriteLine("C : " + c);
                arr[6] = 5;
            }
            catch(DivideByZeroException)
            {
                Console.WriteLine("Exception occured");
            }
            catch(IndexOutOfRangeException)
            {
                Console.WriteLine("I think you dont know how arrays work");
            }
        }
    }
}

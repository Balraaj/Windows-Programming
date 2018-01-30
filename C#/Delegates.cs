using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    delegate void d1<T>(ref T a, ref T b);
    class Delegates
    {
        public void swap(ref int a,ref int b)
        {
            int c;
            c = a;
            a = b;
            b = c;
        }

        public void swap(ref double a ,ref double b)
        {
            double c;
            c = a;
            a = b;
            b = c;
        }

        public static void Main(string[] args)
        {
            Delegates obj = new Delegates();
            d1<int> pt = obj.swap;

            int a = 10;
            int b = 20;

            pt(ref a, ref b);

            Console.WriteLine("A : " + a);
            Console.WriteLine("B : " + b);

            double c = 100;
            double d = 200;

            d1<double> pd = obj.swap;
            pd(ref c, ref d);

            Console.WriteLine("C : " + c);
            Console.WriteLine("D : " + d);

        }
    }
}

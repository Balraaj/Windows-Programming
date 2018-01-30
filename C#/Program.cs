using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class Shape
    {
        public int width;
        public int height;

        public Shape(int w,int h)
        {
            width = w;
            height = h;
        }

     


    }

    class Rectangle:Shape
    {
        public String type;

        public Rectangle(int w,int h,String t):base(w,h)
        {
            type = t;
        }

        public void print()
        {
            Console.WriteLine("Width : " + width);
            Console.WriteLine("Height : " + height);
            Console.WriteLine("Type : " + type);
            Console.WriteLine("Base Width : " + base.width);
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            Rectangle r1 = new Rectangle(10, 50, "Stupid");
            r1.print();
        }
        
    }


}

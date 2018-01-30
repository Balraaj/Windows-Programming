using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    abstract class TwoDShape
    {
        protected double length;
        protected double height;
        string name;

        public TwoDShape(string name, double length, double height)
        {
            this.name = name;
            this.length = length;
            this.height = height;
        }

        public void showName()
        {
            Console.WriteLine("This shape is a : " + name);
        }

        public abstract void area();
    }

    class Triangle:TwoDShape
    {
        string type;

        public Triangle(string type, double length, double height):base("Triangle",length,height)
        {
            this.type = type;
        }

        public override void area()
        {
            Console.WriteLine("Area method called in Triangle");
            Console.WriteLine("Area is : " + (length * height*1/2));
        }
    }

    class Rectangle:TwoDShape
    {
        public Rectangle(double length,double height):base("Rectangle",length,height)
        {

        }

        public override void area()
        {
            Console.WriteLine("Area method called in Rectangle class");
            Console.WriteLine("Area is : " + (length * height));
        }
    }

    public class Test
    {
        public static void Main(string[] args)
        {
            TwoDShape baseObj;
            baseObj = new Triangle("Equilateral", 34, 23);
            baseObj.area();

            baseObj = new Rectangle(23, 14);
            baseObj.area();

            Console.Read();
        }
    }
}

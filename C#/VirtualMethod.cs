using System;

namespace MyProject
{
   abstract class Shape
    {
        protected int length;
        protected int height;
        protected String type;

       protected Shape(String type)
        {
            length = height = 0;
            type = "Generic";
        }

       protected Shape(int x,String type)
        {
            length = height = x;
            this.type = type;
        }

       protected Shape(int length ,int height,String type)
        {
            this.length = length;
            this.height = height;
            this.type = type;
        }

       protected Shape(Shape obj,String type)
        {
            this.length = obj.length;
            this.height = obj.height;
            this.type = type;
        }

        public abstract void Area();

        virtual public void showType()
        {
            Console.WriteLine("Type is : " + type);
        }

    }


    class Rectangle:Shape
    {
        public Rectangle():base("Rectangle")
        {

        }

        public Rectangle(int x):base(x,"Rectangle")
        {
            
        }

        public Rectangle(int length,int height):base(length,height,"Rectangle")
        {

        }

        public override void Area()
        {
            Console.WriteLine("Area is : " + (length * height));
        }

        override public void showType()
        {
            Console.WriteLine("Type called in Rectangle");
        }
    }

    class Triangle : Shape
    {
        public Triangle() : base("Triangle")
        {

        }

        public Triangle(int x) : base(x, "Triangle")
        {

        }

        public Triangle(int length, int height) : base(length, height, "Triangle")
        {

        }

        public override void Area()
        {
            Console.WriteLine("Area is : " + (length * height*1/2));
        }

        override public void showType()
        {
            Console.WriteLine("Type called in Triagnle");
        }

        public void myFunc()
        {
            Console.Write("Hello There");
        }
    }

    public class VirtualTest
    {
        public static void Main(string[] args)
        {
            Shape obj = new Rectangle(12, 12);
            obj.showType();
            obj.Area();

            obj = new Triangle(13, 5);
            obj.showType();
            obj.Area();
            Triangle t = (Triangle)obj;
            t.myFunc();
        }
    }

}

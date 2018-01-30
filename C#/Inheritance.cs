using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class Vehical
    {
        protected string type;

        public Vehical(string type)
        {
            this.type = type;
        }

        public virtual string getType()
        {
            return this.type;
        }
    }

    class Car:Vehical
    {
        public Car(string type) :base(type) { }
        
       override public string getType()
        {
            return this.type;
        }
    }

    class Inheritance
    {
        public static void Main(string[] args)
        {
            Car c = new Car("Mustang GT");
            Vehical v = new Vehical("Truck");

            Vehical temp;
            temp = c;
            string type = temp.getType();

            Console.WriteLine("Your car is : " + type);

            temp = v;
            type = temp.getType();
            Console.WriteLine("Your vehical is : " + type);
        }
        
    }
}

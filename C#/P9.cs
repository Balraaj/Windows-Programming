/* Write a program to create a thread, give it a name "USICT" and display its name. */

using System;
using System.Threading;

namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            Thread myThread = new Thread(Func);
            myThread.Start();
            Console.Read();
        }

        public static void Func()
        {
            Thread myThread = Thread.CurrentThread;
            myThread.Name = "USICT";
            Console.WriteLine("\n\nName of Thread is : " + myThread.Name);
        }
    }
}

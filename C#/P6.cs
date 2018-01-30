/* Write a program to write and read the file abc.txt with the contents "USICT GGSIPU" apply proper
 * exception handling mechanism */

using System;
using System.IO;

namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            try
            {
                StreamWriter sw = new StreamWriter("abc.txt");
                string str = "USICT GGSIPU";
                Console.WriteLine("Writing to File\n");
                sw.WriteLine(str);
                sw.Close();
            }
            catch(Exception e)
            {
                Console.Write(e);
            }

            try
            {
                StreamReader sr = new StreamReader("abc.txt");
                string line;

                Console.Write("Reading from file\nFile contents : ");
                while ((line = sr.ReadLine()) != null)
                {
                    Console.WriteLine(line);
                }

                sr.Close();
            }
            catch(Exception e)
            {
                Console.Write(e);
            }

            Console.Read();
        }
    }
}

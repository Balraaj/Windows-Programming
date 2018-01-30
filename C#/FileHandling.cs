using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MyProject
{
    class FileHandling
    {
        public static void Main(string[] args)
        {
            try
            {
                StreamWriter sw = new StreamWriter("balraj.txt");

                string line;

                while ((line = Console.ReadLine()) != "STOP")
                {
                    sw.WriteLine(line);
                }

                sw.Close();
            }
            catch
            {

            }

            try
            {
                StreamReader sr = new StreamReader("balraj.txt");

                string line;

                Console.WriteLine("\n\nFile contents : \n");
                while((line=sr.ReadLine())!=null)
                {
                    Console.WriteLine(line);
                }

                sr.Close();
            }
            catch
            {

            }
        }
    }
}

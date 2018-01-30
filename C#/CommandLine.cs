using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class CommandLine
    {
        public static void Main(string[] args)
        {
            if(args.Length>0)
            {
                int a = Convert.ToInt32(args[0]);
                int b = Convert.ToInt32(args[1]);

                Console.WriteLine("Sum : " + (a + b));
            }
        }
    }
}

using System;
namespace MyProject
{
    class MyClass
    {
        public static void Main(string[] args)
        {
            int n = 0;
            Console.Write("Enter no : ");
            n = Convert.ToInt32(Console.ReadLine());

            int temp = n;
            int digits = 0;
            int[] arr = new int[10];

            for(int i = 0;temp!=0;temp/=10,i++)
            {
                digits++;
                arr[i] = temp % 10;
            }

            int result = 0;
            for(int i =0;i<digits;i++)
            {
                result+=(int)Math.Pow(arr[i], digits);
            }

            if(result==n)
            {
                Console.WriteLine("No. is Armstrong");
            }
            else
            {
                Console.WriteLine("No. is not Armstrong");
            }

            Console.Read();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyProject
{
    class Stack
    {
        int top;
        int size;
        int[] arr;


        public Stack(int size)
        {
            this.size = size;
            arr = new int[size];
            top = 0;
        }

        public void push(int x)
        {
            if(top==size)
            {
                Console.WriteLine("Stack is full");
                return;
            }
            else
            {
                arr[top++] = x;
            }
        }

        public void pop()
        {
            if(top==0)
            {
                Console.WriteLine("Stack is empty");
            }

            else
            {
                top--;
            }
        }

        public void printStack()
        {
            for(int i=0;i<top;i++)
            {
                Console.WriteLine("{0}", arr[i]);
            }
        }
    }

    class check
    {
        public static void Main(string[] args)
        {
            Stack s = new Stack(10);

            for (int i = 0; i < 15; i++)
            {
                s.push(i);
            }

            s.printStack();

            for(int i =0;i<20;i++)
            {
                s.pop();
            }
        }
    }
}

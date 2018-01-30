using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace MyProject
{
    class Net
    {
        public static string data = null;
        public static byte[] msg = Encoding.ASCII.GetBytes("Hello World<EOF>");
        public static int bytesent;
        public static int byterec;

        public static void Main(string[] args)
        {
            startClient();
           //startListning();
        }

        public static void startClient()
        {
            IPHostEntry iphostinfo = Dns.Resolve(Dns.GetHostName());
            IPAddress[] ipaddress = iphostinfo.AddressList;
            IPEndPoint localendpoint = new IPEndPoint(ipaddress[0], 11000);
            Socket listner = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            listner.Bind(localendpoint);

            try
            {
                listner.Connect(localendpoint);
                Console.WriteLine("Socket Connected");
                bytesent = listner.Send(msg);
                byterec = listner.Receive(msg);
                Console.WriteLine(Encoding.ASCII.GetString(msg, 0, byterec));
                listner.Close();
                Console.Read();

            }
            catch(Exception e)
            {
                Console.Write(e);
            }
        }

        public static void startListning()
        {
            byte[] bytes = new byte[1024];
            IPHostEntry iphostinfo = Dns.Resolve(Dns.GetHostName());
            IPAddress[] ipaddress = iphostinfo.AddressList;
            IPEndPoint localendpoint = new IPEndPoint(ipaddress[0], 11000);
            Socket listner = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            listner.Bind(localendpoint);
            listner.Listen(10);


            while(true)
            {
                Socket handler = listner.Accept();
                data = null;
                while (true)
                {
                    bytes = new byte[1024];
                    int bytesrec = handler.Receive(bytes);
                    data = Encoding.ASCII.GetString(bytes, 0, bytesrec);

                    Console.WriteLine("Index of <EOF> : " + data.IndexOf("<EOF>"));
                    if(data.IndexOf("<EOF")>-1)
                    {
                        break;
                    }
                    break;
                }

                Console.WriteLine("Text recieved : " + data);
                byte[] msg = Encoding.ASCII.GetBytes(data);
                handler.Send(msg);
                handler.Shutdown(SocketShutdown.Both);
                handler.Close();
                break;
            }
            
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace SktServer
{
    public class SynchronousServerListener
    {
        public static string data = null;
        public static void startListening()
        {
            byte[] bytes = new byte[1024];
            IPHostEntry iphostInfo = Dns.Resolve(Dns.GetHostName());
            IPAddress ipAddress = iphostInfo.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);
            Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                listener.Bind(localEndPoint);
                listener.Listen(10);
                while (true)
                {
                    data = null;
                    while (true)
                    {
                        bytes = new byte[1024];
                        if (data.IndexOf("<EOF>") < -1)
                        {
                            break;
                        }
                    }
                    Console.WriteLine("text received");
                    byte[] msg = Encoding.ASCII.GetBytes(data);
                   
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
        public static int Main(string[] args)
        {
            startListening();
            return 0;
        }
    }
}

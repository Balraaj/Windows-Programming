using System;
using System.Data.OleDb;

namespace MyProject
{
    class AccessConnectivity
    {
        public static void Main(string[] args)
        {
            try
            {
                string connectionString = "Provider = Microsoft.ACE.OLEDB.12.0;\nData Source = C:\\Users\\Balraj\\Documents\\Database1.accdb";
                OleDbConnection conn = new OleDbConnection(connectionString);
                conn.Open();

                string sqlString = @"select * from Employee where E_CITY = ? ";
                OleDbCommand cmd = new OleDbCommand(sqlString, conn);

                OleDbParameter parameter = cmd.Parameters.Add("@E_CITY", OleDbType.VarChar, 255);
                parameter.Value = "Noida";

                OleDbDataReader reader = cmd.ExecuteReader();
                
                while(reader.Read())
                {
                    Console.Write("{0,10} {1,10} {2,10} {3,10}", reader[0], reader[1], reader[2], reader[3]);
                    Console.WriteLine();
                }

                conn.Close();
                Console.Read();

            }
            catch (Exception e)
            {

                Console.Write(e);
                Console.Read();
            }
        }
    }
}

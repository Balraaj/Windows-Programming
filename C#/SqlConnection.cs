using System;
using System.Data.SqlClient;

namespace MyProject
{
    class SqlConnectivity
    {
        public static void Main(string[] args)
        {
            try
            {
                string connectionString = @"Server=localhost\SQLEXPRESS;Database=MyDb;Trusted_Connection=True;";
                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open();

                string sqlString = "insert into Employee (E_ID,E_NAME,E_CITY,E_DEPT) values (6,'Himesh','Chandigarh','HR')";
                SqlCommand cmd = new SqlCommand(sqlString, conn);

                cmd.ExecuteNonQuery();

                sqlString = "select * from Employee";
                cmd.CommandText = sqlString;

                SqlDataReader reader = cmd.ExecuteReader();

                while(reader.Read())
                {
                    Console.Write("{0,10}       {1,10}        {2,10}         {3,10}", reader[0],reader[1],reader[2],reader[3]);
                    Console.WriteLine();
                }

                conn.Close();
                Console.Read();
                
            }
            catch(Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}

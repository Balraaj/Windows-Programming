using System;
using System.Windows.Forms;
using System.Drawing;

namespace MyProject
{
    class MyClass:Form
    {
        public MyClass()
        {
            this.Text = "Main Menu Display";
            this.Size = new Size(500, 500);
            this.StartPosition = FormStartPosition.CenterScreen;
            MainMenu mm = new MainMenu();

            MenuItem m1 = new MenuItem("File");
            mm.MenuItems.Add(m1);
            MenuItem m2 = new MenuItem("Open");
            m1.MenuItems.Add(m2);

            MenuItem o1 = new MenuItem("Project");
            MenuItem o2 = new MenuItem("Website");
            MenuItem o3 = new MenuItem("File Name");

            m2.MenuItems.Add(o1);
            m2.MenuItems.Add(o2);
            m2.MenuItems.Add(o3);

            MenuItem m3 = new MenuItem("Exit");
            mm.MenuItems.Add(m3);
            m3.Click += mmExit;
            Menu = mm;
        }

        public void mmExit(Object sender,EventArgs e)
        {
            Application.Exit();
        }

        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.Run(new MyClass());
        }
    }
}

using System;
using System.Drawing;
using System.Windows.Forms;

namespace MyProject
{
    class ExtP2GUI:Form
    {
        ExtP2GUI()
        {
            Button b1 = new Button();
            b1.Text = "Click me";

            this.Controls.Add(b1);
        }

        static void Main(String[] args)
        {
            Application.EnableVisualStyles();
            Application.Run(new ExtP2GUI());
        }
    }
}

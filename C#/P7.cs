using System;
using System.Drawing;
using System.Windows.Forms;

namespace MyProject
{
    class MyClass:Form
    {
        DateTimePicker dtp = new DateTimePicker();
        string msg;

        public MyClass()
        {
            this.Text = "DATE TIME PICKER";
            this.Size = new Size(500, 500);
            this.StartPosition = FormStartPosition.CenterScreen;
            Button b1 = new Button();
            b1.Text = "Select";
            b1.Location = new Point(100, 200);
            b1.Size = new Size(50, 50);

            this.Controls.Add(b1);
            this.Controls.Add(dtp);

            ToolTip tp = new ToolTip();
            tp.SetToolTip(dtp, "DATE TIME PICKER");

            ToolTip tp1 = new ToolTip();
            tp1.SetToolTip(b1, "BUTTON");
            this.BackColor = Color.SkyBlue;
            dtp.ValueChanged += selectValueChanged;

         
        }

        public void selectValueChanged(object sender,EventArgs e)
        {
            msg = dtp.Value.ToString();
            msg += dtp.Value.Day.ToString();
            MessageBox.Show(msg);
        }

        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.Run(new MyClass());
        }
    }
}

using System;
using System.Drawing;
using System.Windows.Forms;

namespace MyProject
{
    class MyWindow:Form
    {
        Button b1 = new Button();
        Label l1 = new Label();

        public MyWindow():base()
        {
            this.Text = "My Window";
            this.Size = new Size(500, 500);
            this.StartPosition = FormStartPosition.CenterScreen;
            b1.Text = "Click";
            b1.Location = new Point(200, 200);
            b1.Size = new Size(50, 20);
            b1.Click += new EventHandler(onClick);
            b1.Click += new EventHandler(myFunc);
            l1.Text = "Hello world";
            l1.Location = new Point(200, 300);

            this.Controls.Add(b1);
            this.Controls.Add(l1);
        }

        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.Run(new MyWindow());
        }

        public void onClick(object sender,EventArgs e)
        {
            MessageBox.Show("Applicatin Closing");
            //Application.Exit();
        }

        public void myFunc(object sender,EventArgs e)
        {
            MessageBox.Show("This will also be visible");

        }
        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // MyWindow
            // 
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Name = "MyWindow";
            this.Load += new System.EventHandler(this.MyWindow_Load);
            this.ResumeLayout(false);

        }

        private void MyWindow_Load(object sender, EventArgs e)
        {

        }
    }
    
}

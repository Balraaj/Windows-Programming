using System;
using System.Drawing;
using System.Windows.Forms;

namespace MyProject
{
    class MyWindow : Form
    {
        private Label myLabel;
        private Button myButton;
        private Boolean changed = false;
        private ToolTip myToolTip;

        public MyWindow()
        {
            this.Text = "My Application";
            this.Size = new Size(500, 500);
            this.StartPosition = FormStartPosition.CenterScreen;

            myLabel = new Label();
            myLabel.Text = "This is a label";
            myLabel.Location = new Point(100, 100);
            myLabel.Size = new Size(100, 100);

            myButton = new Button();
            myButton.Text = "Exit";
            myButton.Location = new Point(100, 200);
            myButton.Size = new Size(50, 20);
            myButton.Click += new EventHandler(myEventHandler);

            myToolTip = new ToolTip();
            myToolTip.SetToolTip(myLabel,"Hello");
            myToolTip.SetToolTip(myButton, "I am a Button");



            this.Controls.Add(myLabel);
            this.Controls.Add(myButton);
        }

        public void myEventHandler(object sender,EventArgs e)
        {
            string text;
            if(changed)
            {
                text = "Original";
                changed = false;
            }
            else
            {
                text = "Changed";
                changed = true;
            }
            myLabel.Text = text;
        }

        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.Run(new MyWindow());
        }
    }
}

package practicle;
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.awt.event.ActionListener;

public class AppletB extends Applet implements ActionListener
{
    String msg = "";
    Button yes , no;

    public void init()
    {
        yes = new Button("Yes");
        no = new Button("No");

        add(yes);
        add(no);

        yes.addActionListener(this);
        no.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e)
    {
        String str = e.getActionCommand();

        if(str=="Yes")
        {
            msg = "You Pressed Yes";
        }
        else
        {
            msg = "You pressed No";
        }

        repaint();
    }

    public void paint(Graphics g)
    {
        g.drawString(msg,6,100);
    }
}

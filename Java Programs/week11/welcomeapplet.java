import java.awt.*;
import java.applet.*;

/*<applet code="welcomeapplet" width=300 height=200>
  </applet>             
*/

public class welcomeapplet  extends Applet
{ public void init()
  { setBackground(Color.cyan);
    setForeground(Color.red);
   }

  public void paint(Graphics g)
  { g.drawString("Welcome to applet programming ",30,30);
    showStatus("This is status window ");
     
   }
 }

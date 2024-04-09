import java.awt.*;
import java.applet.*;
/*<applet code="scroll" width=400 height=200>
  <param name=message value="A moving Banner ">
  </applet>
   */
   
public class scroll extends Applet implements Runnable
{ String n;
  
  public void init()
  {  setBackground(Color.cyan);
     n=getParameter("message");
     //n="A moving Banner ";
   }
   
  public void start()
  { Thread t=new Thread(this);
    t.start();
   }
   
  public void run()
  { for(;;)
    { try
      { 
        Thread.sleep(100);
        repaint();
      }
      catch(Exception exc)
            {}
     
     }
  }
   
  public void paint(Graphics g)
 { 
  g.drawString(n,100,100);
    n= n.charAt(n.length()-1)+n.substring(0,n.length()-1);
        }  
  }

import java.awt.*;
import java.applet.*;
/*<applet code="multtable" width=400 height =400>
  <param name =number value=5>
 </applet>
*/

public class multtable extends Applet
{ int num;
  String n;
  
  public void start()
  { n=getParameter("number"); 
    num=Integer.parseInt(n);
    }

  public void paint(Graphics g)
   { int i=0;
     for(i=1;i<11;i++)
      g.drawString(num+"*"+i+"="+num*i,30,30*i);           
   } 
 
}

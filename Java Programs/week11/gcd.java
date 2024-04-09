import java.awt.*;
import java.applet.*;

/*<applet code=gcd width=200 height=200>
  <param name =num1 value=5>
  <param name =num2 value=15>
 </applet>
*/

public class gcd extends Applet
{ int a,b,cd=1;
 
  
  public void start()
  { String c,d;
    c= getParameter("num1");
    a=Integer.parseInt(c);
    d= getParameter("num2");
    b=Integer.parseInt(d);
  }
  
  public void paint(Graphics g)
  { int i,k=a;
    if(b<a)
    k=b;
    
    for(i=2;i<=k;i++)
    if((a%i==0)&&(b%i==0))
      cd=i;
     
    g.drawString("Numbers are "+a+" and "+b,30,30);
    g.drawString("GCD is "+cd,30,60);
  
   }
}


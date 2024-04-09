import java.awt.*;
import java.applet.*;
/*
<applet code="Multiplication" width=300 height=200>
		<param name="number" value=5>
	</applet>
*/
public class Multiplication extends Applet{
	int num;
	public void start(){
		String param = getParameter("Number");
		try{
			if(param==null)
				throw new Exception();
			num=Integer.parseInt(param);
		}catch(Exception e){
			num=0;
		}
	}
	public void paint(Graphics g){
		for(int i=1;i<=10;i++)
			g.drawString(num+" x "+i+" = "+(num*i),10,13*i);
	}
}
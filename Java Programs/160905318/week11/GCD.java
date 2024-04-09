import java.awt.*;
import java.applet.*;
/*
<applet code="GCD" width=300 height=100>
		<param name="Num1" value=5>
		<param name="Num2" value=10>
	</applet>
*/
public class GCD extends Applet{
	int num1,num2;
	public void start(){
		String param;
		param = getParameter("Num1");
		try{
			if(param==null)
				throw new Exception();
			num1 = Integer.parseInt(param);
		}catch(Exception e){
			num1=1;
		}
		param = getParameter("Num2");
		try{
			if(param==null)
				throw new Exception();
			num2 = Integer.parseInt(param);
		}catch(Exception e){
			num2=1;
		}
	}
	public void paint(Graphics g){
		g.drawString("Number 1:"+num1,10,15);
		g.drawString("Number 2:"+num2,10,30);
		int gcd=gcd(Math.max(num1,num2),Math.min(num1,num2));
		g.drawString("GCD: "+gcd,10,45);
	}
	private int gcd(int a,int b){
		if(b==0)
			return a;
		return gcd(b,a%b);
	}
}
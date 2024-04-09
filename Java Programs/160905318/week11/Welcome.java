import java.awt.*;
import java.applet.*;
/*
<applet code="Welcome" width=300 height=50></applet>
*/
public class Welcome extends Applet{
	public void paint(Graphics g){
		g.drawString("Welcome to applet programming",10,20);
		setBackground(Color.red);
		setForeground(Color.cyan);
		showStatus("This is status window");
	}
}
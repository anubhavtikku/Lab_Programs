import java.awt.*;
import java.applet.*;
/*<applet code="MessageScroll" width=210 height=50></applet>
*/
public class MessageScroll extends Applet implements Runnable{
	String message;
	public void run(){
		while(true){
			try{
				Thread.sleep(250);
				repaint();
			}catch(InterruptedException ie){}
		}
	}
	public void init(){
		message = "Testing scrolling the message ";
	}
	public void start(){
		Thread t=new Thread(this);
		t.start();
	}
	public void paint(Graphics g){
		g.drawString(message,10,15);
		message = message.charAt(message.length()-1)+message.substring(0,message.length()-1);
	}
}
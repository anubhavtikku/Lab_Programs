import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Rectangle extends JPanel{
	JLabel jlab;
	JFrame jframe;
	Point start,end;
	Rectangle(){
		setBorder(BorderFactory.createLineBorder(Color.RED,5));
		JFrame jframe = new JFrame("Draw Rectangles");
		this.jframe=jframe;
		jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jframe.setContentPane(this);
		jframe.setSize(600,500);
		jframe.setVisible(true);
		jlab=new JLabel();
		jframe.add(jlab);
		MyMouseListener list=new MyMouseListener();
		addMouseListener(list);
		addMouseMotionListener(list);
		start=new Point(0,0);
		end=start;
	}
	protected void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.RED);
		int x=(int)start.x;
		int y=(int)start.y;
		int w=(int)end.x-x;
		int h=(int)end.y-y;
		if(w<0){
			x=x+w;
			w=-w;
		}
		if(h<0){
			y=y+h;
			h=-h;
		}
		jlab.setText("Area:"+(w*h));
		g.drawRect(x,y,w,h);
	}
	void setStartPoint(Point p){
		start=p;
	}
	void setEndPoint(Point p){
		end=p;
	}
	public static void main(String args[]){
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				new Rectangle();
			}
		});
	}
	class MyMouseListener extends MouseAdapter{
		public void mousePressed(MouseEvent e){
			setStartPoint(e.getPoint());
		}
		public void mouseReleased(MouseEvent e){
			setEndPoint(e.getPoint());
			repaint();
		}
		public void mouseDragged(MouseEvent e){
			setEndPoint(e.getPoint());
			repaint();
		}
	}
}
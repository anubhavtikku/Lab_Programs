import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Shape extends JPanel{
	JLabel statusLabel;
	JFrame jframe;
	Point start,end;
	int buttonSelected=0;
	JPanel status;
	Shape(){
		setBorder(BorderFactory.createLineBorder(Color.RED,5));
		JFrame jframe = new JFrame("Draw Shapes");
		jframe.setLayout(new BorderLayout());

		JRadioButton oval=new JRadioButton("oval");
		JRadioButton arc=new JRadioButton("arc");
		JRadioButton line=new JRadioButton("line");
		JRadioButton rect=new JRadioButton("rect");
		JRadioButton roundedRect=new JRadioButton("rounded rect");

		this.jframe=jframe;
		jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jframe.setContentPane(this);
		jframe.setSize(600,500);
		jframe.setVisible(true);
		
		jframe.add(oval);
		jframe.add(arc);
		jframe.add(line);
		jframe.add(rect);
		jframe.add(roundedRect);

		//adding action listeners
		ActionListener actlist=new MyListener();
		oval.addActionListener(actlist);
		arc.addActionListener(actlist);
		line.addActionListener(actlist);
		rect.addActionListener(actlist);
		roundedRect.addActionListener(actlist);

		//Button Group
		ButtonGroup bg=new ButtonGroup();
		bg.add(oval);
		bg.add(arc);
		bg.add(line);
		bg.add(rect);
		bg.add(roundedRect);

		//adding status bar
		status=new JPanel();
		//status.setBorder(new BevelBorder(BevelBorder.LOWERED));
		jframe.add(status, BorderLayout.SOUTH);
		status.setPreferredSize(new Dimension(jframe.getWidth(),16));
		status.setLayout(new BoxLayout(status,BoxLayout.X_AXIS));
		statusLabel=new JLabel();
		statusLabel.setHorizontalAlignment(SwingConstants.LEFT);
		status.add(statusLabel);

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
		switch(buttonSelected){
			case 0: g.drawOval(x,y,w,h);
			break;
			case 1: g.drawArc(x,y,w,h,0,180);
			break;
			case 2: g.drawLine(x,y,x+w,y+h);
			break;
			case 3: g.drawRect(x,y,w,h);
			break;
			case 4: g.drawRoundRect(x,y,w,h,45,10);
		}
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
				new Shape();
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
			statusLabel.setText(e.getX()+","+e.getY());
			repaint();
		}
		public void mouseMoved(MouseEvent e){
			statusLabel.setText(e.getX()+","+e.getY());
		}
	}
	class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String action=e.getActionCommand();
			switch(action){
				case "oval":buttonSelected=0;
				break;
				case "arc":buttonSelected=1;
				break;
				case "line":buttonSelected=2;
				break;
				case "rect":buttonSelected=3;
				break;
				case "rounded rect":buttonSelected=4;
			}
		}
	}
}
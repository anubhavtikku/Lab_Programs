import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/* <object code="num" width=200 height=200>
   </object>
  */

public class num extends JApplet
{  JTextField jt1=new JTextField(10);
   JTextField jt2=new JTextField(10);
   JLabel s=new JLabel("");
   JButton b1=new JButton("Add ");
   JButton b2=new JButton("Subtract ");
   JButton b3=new JButton("Multiply ");
   JButton b4=new JButton("Divide ");

   public void init()
   { try{
   	  SwingUtilities.invokeAndWait(new Runnable(){
   	  	public void run()
   	  	{  makeGUI();}
   	  });
   	}catch(Exception exc){}

   }

   public void makeGUI()
   { setSize(300,300);
   	 setLayout(new FlowLayout());
   	 add(jt1);
   	 add(jt2);
   	 add(b1);
   	 add(b2);
   	 add(b3);
   	 add(b4);
   	 add(s);
   	 b1.addActionListener(new ActionListener()
   	 {
   	 	public void actionPerformed(ActionEvent ae)
   	 	{ Float a,b,c;
   	 	  String d="";
          a=Float.parseFloat(jt1.getText());
          b=Float.parseFloat(jt2.getText());
          c=a+b;
          d+=c;
          s.setText(d);
   	 	}
   	 });

     b2.addActionListener(new ActionListener()
   	 {
   	 	public void actionPerformed(ActionEvent ae)
   	 	{ Float a,b,c;
   	 	  String d="";
          a=Float.parseFloat(jt1.getText());
          b=Float.parseFloat(jt2.getText());
          c=a-b;
          d+=c;
          s.setText(d);
   	 	}
   	 });
     
     b3.addActionListener(new ActionListener()
   	 {
   	 	public void actionPerformed(ActionEvent ae)
   	 	{ Float a,b,c;
   	 	  String d="";
          a=Float.parseFloat(jt1.getText());
          b=Float.parseFloat(jt2.getText());
          c=a*b;
          d+=c;
          s.setText(d);
   	 	}
   	 });

   	 b4.addActionListener(new ActionListener()
   	 {
   	 	public void actionPerformed(ActionEvent ae)
   	 	{   Float a,b;
   	 		int c;
   	 		String d="";
          a=Float.parseFloat(jt1.getText());
          b=Float.parseFloat(jt2.getText());
          c=(int) (a/b);
          d+=c;
          s.setText(d);
   	 	}
   	 });

   	  }
   }

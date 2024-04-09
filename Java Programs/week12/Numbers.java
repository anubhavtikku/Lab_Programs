import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*<object code="Numbers" width=600 height=400></object>*/

public class Numbers extends JApplet{
	JButton compute;
	JTextField num1,num2;
	JLabel jlab;

	public void init(){
		try{
			SwingUtilities.invokeAndWait(new Runnable(){
				public void run(){
					makeGUI();
				}
			});
		}catch(Exception ex){
			System.out.println(ex);
		}
	}

	private void makeGUI(){
		setLayout(new FlowLayout(FlowLayout.LEFT));
		setSize(600,400);
		setName("Number Operations");
		System.out.println(this.getClass());

		num1=new JTextField(30);
		num2=new JTextField(30);
		compute=new JButton("Compute");
		jlab=new JLabel();

		add(num1);
		add(num2);
		add(compute);
		add(jlab);

		compute.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				try{
					float a=Float.parseFloat(num1.getText());
					float b=Float.parseFloat(num2.getText());
					String message="";
					message+="sum: "+(a+b);
					message+="   product: "+(a*b);
					message+="   diff: "+(a-b);
					message+="   quotient: "+(int)(a/b);
					jlab.setText(message);
				}catch(Exception ex){
					System.out.println(ex);
				}
			}
		});

	}
}
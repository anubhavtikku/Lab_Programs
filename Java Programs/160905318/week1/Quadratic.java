import java.util.Scanner;
class Quadratic{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter coefficients of x^2, x and constant");
		double a=sc.nextDouble();
		int ch=0;
		double b=sc.nextDouble();
		double c=sc.nextDouble();
		double d=b*b-4*a*c;
		double r1=0.0,r2=0.0;
		try{
			ch=(int) (d/Math.abs(d));
			d=Math.sqrt(Math.abs(d));
		}catch(Exception e){
			r1=-(b/2/a);
			System.out.println("Roots are "+r1+" and "+r1);
		}
		switch(ch){
			case -1:
			r1 = -(b/2/a);
			System.out.println("Roots are "+r1+"+i "+d+"  and  "+r1+"-i "+d);
			break;
			case 1:
			r1 = (d-b)/2/a;
			r2 = -(b+d)/2/a;
			System.out.println("Roots are "+r1+"  and  "+r2);
		}
	}
}

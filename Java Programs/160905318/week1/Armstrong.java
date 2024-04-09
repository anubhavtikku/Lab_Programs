import java.util.Scanner;
class Armstrong{
	boolean isArmstrong(int n){
		int d=0,a=n;
		while(a>0){
			int r=a%10;
			d+=r*r*r;
			a/=10;
		}
		return d==n;
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		int n=sc.nextInt();
		if(new Armstrong().isArmstrong(n))
			System.out.println("Armstrong number");
		else
			System.out.println("Not Armstrong number");
	}
}

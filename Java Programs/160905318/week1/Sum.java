import java.util.Scanner;
class Sum{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		int n=sc.nextInt();
		int a=n;
		int s=0;
		while(a>0){
			s+=a%10;
			a/=10;
		}
		System.out.println("Sum of digits of "+n+"="+s);
	}
}

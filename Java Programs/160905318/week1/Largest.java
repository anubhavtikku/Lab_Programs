import java.util.Scanner;
class Largest{
	int largest(int a,int b,int c){
		return (a>b?(a>c?a:c):(b>c?b:c));
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter 3 numbers");
		int a,b,c;
		a=sc.nextInt();
		b=sc.nextInt();
		c=sc.nextInt();
		Largest ob=new Largest();
		int max=ob.largest(a,b,c);
		System.out.println("Largest number is "+max);
	}
}

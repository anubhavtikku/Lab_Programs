import java.util.Scanner;
class Odd{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of numbers");
		int o=0,e=0;
		int n=sc.nextInt();
		while(n-->0){
			System.out.print("Enter number:");
			if((sc.nextInt()&1)==0)
				e++;
			else
				o++;
		}
		System.out.println("Number of odd numbers="+o+"\nNumber of even numbers="+e);
	}
}

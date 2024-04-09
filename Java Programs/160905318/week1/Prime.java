import java.util.Scanner;
class Prime{
	boolean isPrime(int n){
		int a=(int)Math.ceil(Math.sqrt(n));
		if(n<=1)
			return false;
		for(int i=2;i<=a && i<n;i++)
			if(n%i==0)
				return false;
		return true;
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Prime ob=new Prime();
		System.out.println("Enter value of n");
		int n=sc.nextInt();
		System.out.println("Prime numbers are:-");
		for(int i=2;n>0;i++){
			if(ob.isPrime(i)){
				n--;
				System.out.println(i);
			}
		}
	}
}

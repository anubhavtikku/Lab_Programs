import java.util.Scanner;
class NCR{
	int fact(int n){
		int f=1;
		for(int i=2;i<=n;i++)
			f*=i;
		return f;
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		NCR ob=new NCR();
		System.out.println("Enter value of N and R");
		int n=sc.nextInt();
		int r=sc.nextInt();
		int ncr = ob.fact(n)/ob.fact(r)/ob.fact(n-r);
		System.out.println(n+"C"+r+"="+ncr);
	}
}

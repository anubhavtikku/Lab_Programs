import java.util.*;
class Fibo{
	List<Integer> a;
	Fibo(){
		a=new ArrayList<Integer>();
		a.add(0);
		a.add(1);
	}
	int getFibo(int n){
		if(n>=a.size())
			a.add(getFibo(n-2)+getFibo(n-1));
		return a.get(n);
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Fibo ob=new Fibo();
		System.out.println("Enter number of terms");
		int n=sc.nextInt();
		System.out.println("Fibonacci numbers are");
		for(int i=0;i<n;i++)
			System.out.print(ob.getFibo(i)+" ");
	}
}

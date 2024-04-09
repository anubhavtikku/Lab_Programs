import java.util.Scanner;
class Numbers{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		String s=sc.next();
		for(int i=s.length()-3;i>=0;i-=3)
			s=s.substring(0,i)+","+s.substring(i);
		System.out.println("Modified String:"+s);
	}
}
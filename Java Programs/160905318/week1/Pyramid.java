import java.util.Scanner;
class Pyramid{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of lines");
		int a=sc.nextInt();
		for(int i=1;i<=a;i++){
			for(int j=0;j<i;j++)
				System.out.print("* ");
			System.out.println();
		}
	}
}

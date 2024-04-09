import java.util.Scanner;
class Reverse{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of elements");
		int n=sc.nextInt();
		System.out.println("Enter elements");
		int a[]=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		for(int i=0;i<n/2;i++){
			int t=a[i];
			a[i]=a[n-i-1];
			a[n-i-1]=t;
		}
		System.out.println("Reversed array:-");
		for(int i=0;i<n;i++)
			System.out.print(a[i]+"  ");
		System.out.println();
	}
}

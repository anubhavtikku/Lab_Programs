import java.util.Scanner;
class Linear{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of elements");
		int n=sc.nextInt();
		System.out.println("Enter elements");
		int a[]=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		System.out.println("Enter searching element");
		int sel=sc.nextInt();
		for(int i=0;i<n;i++){
			if(a[i]==sel){
				System.out.println("Found at position :"+i);
				return;
			}
		}
		System.out.println("Element not found");
	}
}

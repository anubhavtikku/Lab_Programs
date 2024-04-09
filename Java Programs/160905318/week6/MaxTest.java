import myPackages.p1.Max;
import java.util.Scanner;
class MaxTest{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter 3 integers");
		System.out.println("Maximum is "+Max.max(sc.nextInt(),sc.nextInt(),sc.nextInt()));
		System.out.println("Enter 3 floating point numbers");
		System.out.println("Maximum is "+Max.max(sc.nextFloat(),sc.nextFloat(),sc.nextFloat()));
		System.out.println("Enter number of elements in array");
		int n=sc.nextInt();
		int a[]=new int[n];
		System.out.println("Enter elements");
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		System.out.println("Maximum is "+Max.max(a));
		System.out.println("Enter dimensions of matrix");
		int r=sc.nextInt();
		int c=sc.nextInt();
		int arr[][]=new int[r][c];
		System.out.println("Enter elements");
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				arr[i][j]=sc.nextInt();
		System.out.println("Maximum is "+Max.max(arr));
	}
}
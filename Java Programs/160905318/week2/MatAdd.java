import java.util.Scanner;
class MatAdd{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int a[][]=input(sc);
		int b[][]=input(sc);
		if(a.length!=b.length || a[0].length!=b[0].length){
			System.out.println("Incompatible matrices for addition");
			return;
		}
		int r=a.length;
		int c=a[0].length;
		int sum[][]=new int[r][c];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				sum[i][j]=a[i][j]+b[i][j];
		System.out.println("Sum of the 2 matrices are");
		for(int i[]:sum){
			for(int j:i)
				System.out.print(j+" ");
			System.out.println();
		}

	}
	static int[][] input(Scanner sc){
		System.out.println("Enter number of rows and columns of the matrix");
		int r=sc.nextInt();
		int c=sc.nextInt();
		int a[][]=new int[r][c];
		System.out.println("Enter elements:");
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				a[i][j]=sc.nextInt();
			}
		}
		return a;
	}
}

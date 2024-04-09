import java.util.Scanner;
class Symmetric{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of rows and columns");
		int r=sc.nextInt();
		int c=sc.nextInt();
		int a[][]=new int[r][c];
		System.out.println("Enter elements");
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				a[i][j]=sc.nextInt();
			}
		}
		if(r!=c){
			System.out.println("Not Symmetric");
			return;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<i;j++){
				if(a[i][j]!=a[j][i]){
					System.out.println("Not Symmetric");
					return;
				}
			}
		}
		System.out.println("Symmetric");

	}
}

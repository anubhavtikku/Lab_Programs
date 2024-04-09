import java.util.Scanner;
class Bubble{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of elements");
		int n=sc.nextInt();
		int a[]=new int[n];
		System.out.println("Enter elements");
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		System.out.println("Enter 1 for ascending and any other number for descending order");
		boolean f = sc.nextInt()==1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if((a[j]>a[j+1] && f) || (a[j]<a[j+1] && !f)){
					int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		System.out.println("Sorted array:-");
		for(int i:a)
			System.out.print(i+"  ");
		System.out.println();
	}
}

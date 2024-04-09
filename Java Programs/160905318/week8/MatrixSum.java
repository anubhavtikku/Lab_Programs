import java.util.Scanner;

class RowSum implements Runnable{
	Thread t;
	int a[],sum;
	RowSum(int a[],int rowNum){
		t=new Thread(this, "Row "+rowNum);
		this.a=a;
		sum=0;
		t.start();
	}
	public void run(){
		for(int i:a)
			sum+=i;
	}
}

class MatrixSum{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of rows and columns");
		int r=sc.nextInt();
		int c=sc.nextInt();
		int a[][]=new int[r][c];
		RowSum rs[]=new RowSum[r];
		System.out.println("Enter elements:");
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				a[i][j]=sc.nextInt();
			rs[i]=new RowSum(a[i],i);
		}
		int sum=0;
		for(int i=0;i<r;i++){
			try{
				rs[i].t.join();
				sum+=rs[i].sum;
			}catch(InterruptedException ex){}
		}
		System.out.println("Sum="+sum);

	}
}

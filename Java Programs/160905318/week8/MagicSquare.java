import java.util.HashSet;
import java.util.Scanner;
class Matrix{
	int a[][],r,c;
	Matrix(int a[][],int n){
		this.a=a;
		this.r=n;
		this.c=n;
	}
}
class CheckUnique implements Runnable{
	Matrix mat;
	boolean isUnique;
	CheckUnique(Matrix mat){
		this.mat=mat;
		isUnique=true;
	}
	public void run(){
		HashSet<Integer> set=new HashSet<Integer>();
		for(int i=0;i<mat.r;i++){
			for(int j=0;j<mat.c;j++){
				if(set.contains(mat.a[i][j])){
					isUnique=false;
					return;
				}
				set.add(mat.a[i][j]);
			}
		}
	}
}
class RowSums implements Runnable{
	int a[];
	int sum;
	RowSums(int a[]){
		this.a=a;
		sum=0;
	}
	public void run(){
		for(int i:a)
			sum+=i;
	}
}
class ColumnSum implements Runnable{
	Matrix mat;
	int sum,colNum;
	ColumnSum(Matrix mat,int colNum){
		this.mat=mat;
		this.colNum=colNum;
		sum=0;
	}
	public void run(){
		for(int i=0;i<mat.r;i++)
			sum+=mat.a[i][colNum];
	}
}
class PrincipalSum implements Runnable{
	Matrix mat;
	int sum;
	PrincipalSum(Matrix mat){
		this.mat=mat;
		sum=0;
	}
	public void run(){
		for(int i=0;i<mat.r;i++)
			sum+=mat.a[i][i];
	}
}
class SecondarySum implements Runnable{
	Matrix mat;
	int sum;
	SecondarySum(Matrix mat){
		this.mat=mat;
		sum=0;
	}
	public void run(){
		for(int i=0;i<mat.r;i++)
			sum+=mat.a[i][mat.r-i-1];
	}
}

class MagicSquare{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter matrix side");
		int n=sc.nextInt();
		System.out.println("Enter matrix");
		int a[][]=new int[n][n];
		Thread t[]=new Thread[2*n+3];
		RowSums rs[]=new RowSums[n];
		ColumnSum cs[]=new ColumnSum[n];
		CheckUnique cu;
		PrincipalSum ps;
		SecondarySum ss;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				a[i][j]=sc.nextInt();
			rs[i]=new RowSums(a[i]);
			t[i]=new Thread(rs[i],"Row "+i);
			t[i].start();
		}
		Matrix mat=new Matrix(a,n);
		for(int i=0;i<n;i++){
			cs[i]=new ColumnSum(mat,i);
			t[i+n]=new Thread(cs[i],"Column "+i);
			t[i+n].start();
		}
		cu=new CheckUnique(mat);
		t[2*n]=new Thread(cu,"Unique");
		t[2*n].start();
		ps=new PrincipalSum(mat);
		t[2*n+1]=new Thread(ps,"Principal Diagonal Sum");
		t[2*n+1].start();
		ss=new SecondarySum(mat);
		t[2*n+2]=new Thread(ss,"Secondary Diagonal Sum");
		t[2*n+2].start();
		int sum=0;
		try{
			t[0].join();
		sum=rs[0].sum;
		for(int i=1;i<n;i++){
			t[i].join();
			if(rs[i].sum!=sum){
				System.out.println("Not Magic");
				return;
			}
		}
		for(int i=0;i<n;i++){
			t[i+n].join();
			if(cs[i].sum!=sum){
				System.out.println("Not Magic");
				return;
			}
		}
		t[2*n].join();
		if(!cu.isUnique){
			System.out.println("Not Magic");
			return;
		}
		t[2*n+1].join();
		if(ps.sum!=sum){
			System.out.println("Not Magic");
			return;
		}
		t[2*n+2].join();
		if(ss.sum!=sum){
			System.out.println("Not Magic");
			return;
		}
	}catch(InterruptedException e){
		System.out.println(e);
	}
		System.out.println("Magic Square");
	}

}
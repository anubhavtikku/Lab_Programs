import java.util.Scanner;
class InsDel{
	int a[],n,curr;
	InsDel(int n){
		this.n=n;
		a=new int[n];
		curr = 0;
	}
	void insert(int num,int pos){
		if(curr==n){
			System.out.println("Array full");
			return;
		}
		if(pos<0 || pos>curr){
			System.out.println("Invalid position");
			return;
		}
		for(int i=curr;i>pos;i--)
			a[i]=a[i-1];
		a[pos]=num;
		curr++;
		System.out.println("Inserted successfully");
	}
	void delete(int num){
		for(int i=0;i<curr;i++){
			if(a[i]==num){
				curr--;
				for(int j=i;j<curr;j++)
					a[j]=a[j+1];
				System.out.println("Deleted");
				return;
			}
		}
		System.out.println("Element not found");
	}
	void display(){
		System.out.println("Elements in array are:-");
		for(int i=0;i<curr;i++)
			System.out.print(a[i]+"  ");
		System.out.println();
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter capacity of array");
		int n=sc.nextInt();
		InsDel ob=new InsDel(n);
		while(true){
			System.out.println("Enter 1 to insert, 2 to delete ,3 to display and 4 to exit");
			int ch=sc.nextInt();
			switch(ch){
				case 1: System.out.println("Enter number to insert and position");
				ob.insert(sc.nextInt(),sc.nextInt());
				break;
				case 2: System.out.println("Enter number to delete");
				ob.delete(sc.nextInt());
				break;
				case 3: ob.display();
				break;
				case 4: return;
				default: System.out.println("Wrong entry");
			}
		}
	}
}

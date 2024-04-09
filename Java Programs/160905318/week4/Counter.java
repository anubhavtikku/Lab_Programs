import java.util.Scanner;
class Counter{
	static int count=0;
	Counter(){
		Counter.count++;
	}
	static void showCount(){
		System.out.println("No of objects = "+count);
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Counter ob;
		while(true){
			System.out.println("1. Create 2. Display 3. Exit");
			switch(sc.nextInt()){
				case 1: System.out.println("Enter no of objects to create");
				int c=sc.nextInt();
				for(int i=0;i<c;i++)
					ob=new Counter();
				break;
				case 2: Counter.showCount();
				break;
				case 3: return;
			}
		}
	}
}
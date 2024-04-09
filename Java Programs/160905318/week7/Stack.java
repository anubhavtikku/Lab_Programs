import java.util.LinkedList;
import java.util.Scanner;
interface Stack{
	void push(int n);
	int pop();
	void display();
}

class FixedStack implements Stack{
	int arr[],top,cap;
	FixedStack(int cap){
		this.cap=cap;
		top=-1;
		arr=new int[cap];
	}
	public void push(int n){
		if(top>=cap-1){
			System.out.println("Stack is full");
			return;
		}
		arr[++top]=n;
	}
	public int pop(){
		if(top<0){
			System.out.println("Stack empty");
			return Integer.MIN_VALUE;
		}
		return arr[top--];
	}
	public void display(){
		for(int i=0;i<=top;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
}

class DynamicStack implements Stack{
	LinkedList<Integer> list;
	DynamicStack(){
		list=new LinkedList<Integer>();
	}
	public void push(int n){
		list.addFirst(n);
	}
	public int pop(){
		if(list.size()==0){
			System.out.println("Stack empty");
			return Integer.MIN_VALUE;
		}
		return list.remove();
	}
	public void display(){
		Object arr[]=list.toArray();
		for(Object i:arr)
			System.out.print(((Integer)i)+" ");
		System.out.println();
	}
}

class TestStack{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		Stack st;
		System.out.println("Enter 1 for fixed size and 2 for Dynamic Stack");
		int ch=sc.nextInt();
		if(ch==1){
			System.out.println("Enter capacity");
			st=new FixedStack(sc.nextInt());
		}
		else if(ch==2)
			st=new DynamicStack();
		else{
			System.out.println("Incorrect choice");
			return;
		}
		while(true){
			System.out.println("1. Push 2. Pop 3. Display 4. Exit");
			ch=sc.nextInt();
			switch (ch) {
				case 1: System.out.println("Enter element");
				st.push(sc.nextInt());
				break;
				case 2: int n=st.pop();
				if(n!=Integer.MIN_VALUE)
					System.out.println("Popped:"+n);
				break;
				case 3: st.display();
				break;
				case 4:return;
			}
		}
	}
}
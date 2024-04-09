import java.util.Scanner;
interface Series{
	int getNext();
	void reset();
	void setStart(int n);
}

class ByTwos implements Series{
	int first,next;
	public int getNext(){
		next+=2;
		return next;
	}
	public void reset(){
		next=first;
	}
	public void setStart(int n){
		first=next=n;
	}
}

class SeriesTest{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Series se=new ByTwos();
		while(true){
			System.out.println("1. Set first element 2. Reset 3. Get Next Element 4. Exit");
			int ch=sc.nextInt();
			switch(ch){
				case 1: se.setStart(sc.nextInt());
				break;
				case 2: se.reset();
				break;
				case 3: System.out.println(se.getNext());
				break;
				case 4: return;
			}
		}
	}
}
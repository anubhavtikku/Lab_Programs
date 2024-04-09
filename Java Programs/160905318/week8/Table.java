class Table{
	static void display(int x){
		for(int i=1;i<=10;i++)
			System.out.println(i+" * "+x+" = "+(i*x));
	}
}

class DisplayTable implements Runnable{
	int x;
	Thread t;
	DisplayTable(int x){
		this.x=x;
		t=new Thread(this,"Table of "+x);
		t.start();
	}
	public void run(){
		Table.display(x);
	}
}

class TableDemo{
	public static void main(String args[])throws InterruptedException{
		DisplayTable t5 = new DisplayTable(5);
		DisplayTable t7 = new DisplayTable(7);
	}
}

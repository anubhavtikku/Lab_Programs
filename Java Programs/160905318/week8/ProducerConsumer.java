class Q{
	int n;
	boolean isSet;
	Q(){
		n=0;
		isSet = false;
	}
	synchronized int get(){
		while(!isSet){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Caught InterruptedException");
			}
		}
		System.out.println("Get:"+n);
		isSet=false;
		notify();
		return n;
	}
	synchronized void set(int n){
		while(isSet){
			try{
				wait();
			}catch(InterruptedException e){
				System.out.println("Caught InterruptedException");
			}
		}
		System.out.println("Set:"+n);
		this.n=n;
		isSet=true;
		notify();
	}
}
class Producer implements Runnable{
	Thread t;
	Q q;
	Producer(Q q){
		this.q=q;
		t=new Thread(this,"Producer");
		t.start();
	}
	public void run(){
		for(int i=0;true;i++)
			q.set(i);
	}
}
class Consumer implements Runnable{
	Thread t;
	Q q;
	Consumer(Q q){
		this.q=q;
		t=new Thread(this,"Consumer");
		t.start();
	}
	public void run(){
		while(true)
			q.get();
	}
}


class ProducerConsumer{
	public static void main(String args[]){
		Q q=new Q();
		Producer prod=new Producer(q);
		Consumer cons=new Consumer(q);
	}
}

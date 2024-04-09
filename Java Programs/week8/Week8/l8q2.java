class Table{
static void display(int x)
{
for(int i = 1; i<=10;i++)
System.out.println(x+" * "+i+" = "+ (x*i) );
}
}

class DisplayTable extends Thread{
int x;
DisplayTable(int x)
{
super("Thread"+x);
this.x=x;
start();
}

public void run()
{
Table.display(x);
}
}

class l8q2{
public static void main(String [] args)
{
try{
new DisplayTable(5).join();
new DisplayTable(7).join();
}catch(InterruptedException ie)
{}
}
}

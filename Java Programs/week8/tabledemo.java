import java.io.*;
import java.util.*;

class  DisplayTable extends Thread
{  int x;
   Thread t;

   DisplayTable(int x)
   { this.x=x;
   	 t=new Thread(this);
   	 t.start();
   }

   public void run()
   {
      table.display(x); 
   }

  }

class table
{ static void display(int x)
	{ int i; 
  	  for(i=1;i<11;i++)	
      System.out.println(i+"*"+x+"="+i*x);
	}

}

class tabledemo
{ public static void main(String args[])
  {  try{
  	 DisplayTable t1=new DisplayTable(5);
  	 t1.t.join();
  	 DisplayTable t2=new DisplayTable(7);
    }catch(InterruptedException exc)
    {}
  }
}
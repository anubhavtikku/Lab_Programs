import java.io.*;
import java.util.*;

interface Series
{
  int getNext();
  void reset();
  void setStart(int x);

}

class ByTwos implements Series
{ int val;
  int start;

  ByTwos()
  { val=0;
    start=0;
  }
  
  public int getNext()
  { val=val+2;
    return val;
  }

  public void reset()
  {
  	val=start;
  }

  public void setStart(int x)
  {
    start=x;
  }

}

class serie
{ public static void main(String args[])
	{ int x;
	  ByTwos t1=new ByTwos();
      Scanner s=new Scanner(System.in);
		do
        { System.out.println("Enter 1.To set Start 2.To reset 3.To get next number 4.Exit ");
          x=s.nextInt();

          if(x==1)
          { int ele; 
            System.out.println("Enter element ");
            ele=s.nextInt();
            t1.setStart(ele);
          }

          if(x==2)
          { t1.reset();
          }

          if(x==3)
          { System.out.println(t1.getNext()+"\t");

          }

        }while(x==1 || x==2 || x==3);
	}
}
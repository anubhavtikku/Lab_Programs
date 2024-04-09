import java.io.*;
import java.util.*;

class SeatFilledException extends Exception
{
	public SeatFilledException()
	{
		System.err.println("All seats have been filled ");
	}
}

class stud
{ int regno;
  int year;
  String name;

  stud(String n,int y,int s) throws SeatFilledException
  { name=n;
  	year=y;
  	regno=(y%100)*100+s;
    if (regno%100>25)
    	throw new SeatFilledException();
  }

 void d()
 {
       System.out.println("\nName "+name+" Reg No. "+regno+" Year "+year);
 }

}

class stu
{ public static void main(String args[])
	{ String n; 
	  int y,se;
	  Scanner s=new Scanner(System.in);
	  System.out.println("Enter name of student ");
      n=s.nextLine();
      System.out.println("Enter year of student ");
      y=s.nextInt();
      System.out.println("Enter seat no of student ");
      se=s.nextInt();
      stud t1;
      try
      {
      	t1=new stud(n,y,se);
      	t1.d();
      }
      catch(SeatFilledException exc)
      { System.out.println("Seat Filled Exception: "+exc);
          
      }

	}
}


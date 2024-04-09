import java.io.*;
import java.util.*;

class employee
{ String name;      
  int age;         
  double gsalary;
  float  hsalary;
  char grade;

  employee()
  { name="Smith";
    grade='F';
  }

  void input() 
  {try{ 
  	System.out.println("Enter name,age,gSalary,hSalary and grade ");
    Scanner sc=new Scanner(System.in);
    name=sc.nextLine();
    
    String a=sc.nextLine();
    age=Integer.parseInt(a);

    if(age<=0 || age>100)
    	throw new IOException();
    
    String g=sc.nextLine();
    gsalary=Double.parseDouble(g);
    if(gsalary<=0)
    	throw new IOException();

    String h=sc.nextLine();
    hsalary=Float.parseFloat(h);
    if(hsalary<=0)
    	throw new IOException();
    
    grade=sc.next().charAt(0);
    }
      catch(IOException exc)
    {
    	System.out.println("IO Exception - Incorrect Input ");
    	name="Smith";
    	age=0;
        gsalary=0;
        hsalary=0;
    }

    }
           
     
  void disp()
  { System.out.println("Name "+name+" Age "+age+" Gross Salary "+gsalary+" Home Salary "+hsalary+" Grade "+grade); 
    }

  }

 class e
{ public static void main(String args[])
  { employee t1=new employee();
    int x=1;
    Scanner s=new Scanner(System.in);
    do
    { System.out.println("Enter 1.To input 2.To display 3.Exit ");
      x=s.nextInt();
     
      if(x==1)
      t1.input();
     
      if(x==2)
      t1.disp();
      
      
   }    while(x==1 || x==2);

  }
}


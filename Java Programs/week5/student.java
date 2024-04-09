import java.io.*;
import java.util.*;
import java.lang.*;

class stu
{ int reg;
  String fullname;
  Calendar cal=new GregorianCalendar();
  short semester;
  float gpa;
  float cgpa;
  static int m1=0;
      
  stu(int r,String f,GregorianCalendar d,short s,float g,float c)
 { 
   reg=r;
   fullname=f;
   cal=d;
   semester=s;
   gpa=g;
   cgpa=c;
  }

 stu()
 {  
    cal=new GregorianCalendar();
    fullname="";
    reg=0;
    gpa=0;
    cgpa=0;
    semester=1;
   }

 void display()
 { System.out.print("\n\nReg No. "+reg+"\nFull Name "+fullname+"\nDate "+cal.get(Calendar.DATE));
   System.out.println("-"+cal.get(Calendar.MONTH)+"-"+cal.get(Calendar.YEAR)+"\nSemester "+semester+"\nGPA "+gpa+"\nCGPA "+cgpa);
  }

static void sorts(stu a[])
    {  int i,k; 
       stu temp=new stu();
       for(i=0;i<3;i++)
       for(k=0;k<2-i;k++)
       if(a[i].semester>a[i+1].semester)
        {temp=a[i];
         a[i]=a[i+1];
         a[i+1]=temp;
         }
       
       for(i=0;i<3;i++)
       for(k=0;k<2-i;k++)
       if((a[i].semester==a[i+1].semester)&&(a[i].cgpa>a[i+1].cgpa))
        {temp=a[i];
         a[i]=a[i+1];
         a[i+1]=temp;
         } 
       
       }    

static  void sortn(stu a[])
   { int i,k;
   	 stu temp=new stu();
   	 for(i=0;i<3;i++)
       for(k=0;k<2-i;k++)
     if((a[i].fullname.compareTo(a[i+1].fullname)>0))
     { temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
      }
  }

static  void ch(stu a[])
   { int i,k;
   	 char z;
   	 Scanner s=new Scanner(System.in);
   	 System.out.println("Enter Character ");
     z=s.next().charAt(0);
     for(i=0;i<3;i++)
     if(a[i].fullname.charAt(0)==z)
      { a[i].display();
      }
   }

static void sub(stu a[])
{ String q;
  int i;
  System.out.println("Enter String ");
  Scanner s=new Scanner(System.in);
  q=s.nextLine();
  for(i=0;i<3;i++)
  if(a[i].fullname.contains(q))
    a[i].display();
 }

void chna()
{ StringTokenizer st=new StringTokenizer(this.fullname); 
  String f="",l="";
  while(st.hasMoreTokens())
  { l=st.nextToken();
  	if(st.hasMoreTokens())
  	f=f+l.charAt(0)+". ";
  }
  f=f+l;
  this.fullname=f;
   }

 void input()
 {     Scanner s=new Scanner(System.in);
       int d,m,y;
 	   System.out.println("\nEnter Name ,Semester ,GPA and CGPA for  student"+(m1+1)); 
      this.fullname=s.nextLine();
      this.semester=s.nextShort();
      this.gpa=s.nextFloat();
      this.cgpa=s.nextFloat();
      System.out.println("Enter date ,month and year of joining ");
      d=s.nextInt();
      m=s.nextInt();
      y=s.nextInt();
      this.cal=new GregorianCalendar(y,m,d);
      this.reg=(y%100)*100+(++m1); }


 };


class student
{ public static void main(String args[])
  { stu a[]=new stu[3];
    int i,x=0;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter three student records"); 
    for(i=0;i<3;i++)
    {  a[i]=new stu();
       a[i].input();
      }
do
{System.out.println("\n1. Display Records" + 
					"\n2. Sort according Name " +
					"\n3. Sort according Semester "+
					"\n4. List all Students whose name begins with a character." +
					"\n5. List all Students whose name contains a string." +
					"\n6. Shorten name to initials for all students " +
			        "\n7. Exit ");
	x=s.nextInt();
  
  switch(x)
  {case 1: for(i=0;i<3;i++)
           a[i].display();
           x=0;
           break;
   case 2: a[0].sortn(a);
           x=0;
           break;
   case 3: a[0].sorts(a);
           x=0;
           break;
   case 4: a[0].ch(a);
           x=0;
           break;
   case 5: a[0].sub(a);
           x=0;
           break;
   case 6: for(i=0;i<3;i++)
           a[i].chna();
           x=0;
           break;                                          
 }


}while(x==0);

}
}


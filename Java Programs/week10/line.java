import java.io.*;
import java.util.*;

class line
{ public static void main(String args[])
  { FileReader in=null;
    FileWriter out=null;
    
    try
    { in=new FileReader("/home/student/Desktop/160905404/week10/fileNames.txt");
      int r,k;
      String a,b,c;
      int lc=0;
      Scanner s=new Scanner(in);
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter word ");
      b=sc.nextLine();
       
      while(s.hasNextLine())
     { a=s.nextLine();
     	lc+=1;
     	k=1;
       StringTokenizer st=new StringTokenizer(a); 
       while(st.hasMoreTokens() && k==1)
       { c=st.nextToken();
    	 if(c.equals(b))
         {System.out.println("Line "+lc+" "+a);
            k=0;
        }
        }       
     } 
     }
     catch(Exception e)
     { e.printStackTrace(); }
  
  }
}

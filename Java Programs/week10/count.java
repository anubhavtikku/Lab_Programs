import java.io.*;
import java.util.*;

class count
{ public static void main(String args[])
  { FileReader in=null;
    FileWriter out=null;
    
    try
    { in=new FileReader("/home/student/Desktop/160905404/week10/fileNames.txt");
      int r;
      String a;
      int sen=0,words=0,chars=0,dig=0;
      while((r=in.read())!=-1)
      {  char c=(char)r;
         if(c=='\n')
         sen+=1;
         if(  ((c>=65)&&(c<=90))  ||  ((c>=97)&&(c<=122)) )
         chars+=1;
         if((c<58)&&(c>47))
         dig+=1;
         
         if(c==' '||c=='\n')
         words+=1;
            
          }
          
      System.out.println("Chars "+chars+" Digits "+dig+" Sentences "+sen+" Words "+words);
     }
     catch(Exception e)
     { e.printStackTrace(); }
      
   }
    }

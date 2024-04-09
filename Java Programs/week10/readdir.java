import java.io.*;
import java.util.*;

public class readdir
{ 
  static void rec(String paths[],int k)
  { 
       
       if(k==paths.length)
       {return ; }
       
       System.out.println(paths[k]);
        
     rec(paths,k+1);
    }


  public static void main(String args[])  
  { File file=new File("/home/student/Desktop/160905404/");
    String []paths;
    
    if(file.isDirectory())
   { try
    {  
       paths=file.list();
       System.out.println("Directory name is "+file);
       
       int k=0;   
               
       rec(paths,k);         
       }
    catch(Exception e)
    { e.printStackTrace();
      }
      }   
  }  
  }

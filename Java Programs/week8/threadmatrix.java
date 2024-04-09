import java.io.*;
import java.util.*;

class rowsum implements Runnable
 {  int a[];
    int n;
    public int rowsu;
    Thread t;

    rowsum(int b[],int n)
    {t=new Thread(this,""+n);
     int rowsu=0;
     a=b;
     this.n=n;
     t.start();
     }

  public void run()
 {  int i;
    try {
        for(i=0;i<n;i++)
        rowsu+=a[i];
       
         } catch(Exception e)
    {
    System.out.println("Interrupted Exception occured");
    
    }
  System.out.println("Rowsum is "+rowsu);
  } 

 }

class threadmatrix
{ public static void main(String args[])
  { int i,j,m,n,totalsum=0;
    int a[][]=new int[10][10];
    Scanner s=new Scanner(System.in);
    System.out.println("Enter dimensions of matrix ");
    m=s.nextInt();
    n=s.nextInt();

    rowsum t1[]= new rowsum[m];
    
    System.out.println("Enter values ");
    try{
    for(i=0;i<m;i++)
    { for(j=0;j<n;j++)      
      a[i][j]=s.nextInt();
      t1[i]=new rowsum(a[i],n);
      t1[i].t.join();
      totalsum+=t1[i].rowsu;
    }
    System.out.println("Total Sum is "+totalsum);
   }catch(InterruptedException exc)
     {
      
     }

     }    
  }   
  

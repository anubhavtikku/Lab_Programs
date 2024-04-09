import java.util.*;
import java.lang.*;

class RowSumThread implements Runnable{
public int partialSum;
int row[];
Thread t;

 RowSumThread(String TName, int row[])
 {
    this.row = row;
    partialSum = 0;
    t = new Thread(this, TName);
    t.start();
 }
 
 public void run()
 {
    try{
    for(int i=0;i<row.length;i++)
    {
      partialSum+=row[i];
    }
    }catch(Exception e){
     System.out.println("Interrupted Exception occured");
    }
    System.out.println("PartSum is: "+partialSum+"\nExiting "+t);
 }
}

class l8q1{

 public static void main(String[] args)
 {
    Scanner sc = new Scanner(System.in);
    int m,n;
    System.out.print("Input number of rows and columns respectively: ");
    m=sc.nextInt();
    n=sc.nextInt();
    
    RowSumThread r[] = new RowSumThread[m];
    int arr[][]= new int[m][n];
    int totalSum=0;
    System.out.println("Now input the 2D array-");
    try
    {
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
        arr[i][j]=sc.nextInt();
      r[i] = new RowSumThread("Thread"+(i+1),arr[i]);
      r[i].t.join();
      totalSum+=r[i].partialSum;
     }  
     System.out.println("Sum is: "+totalSum); 
    }catch(InterruptedException ie)
    {}
 }
}

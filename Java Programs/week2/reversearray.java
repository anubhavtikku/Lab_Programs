import java.io.*;
import java.util.*;

class reversearray
{  
   public static void main(String args[])
    { int n,i,j,temp;
      int a[]=new int[20];
          
      Scanner s=new Scanner(System.in);

      System.out.println("Enter no of integers ");
      n=s.nextInt();

      System.out.println("Enter integers ");

      for(i=0;i<n;i++)
      a[i]=s.nextInt();

      System.out.println("The array is ");
      for(i=0;i<n;i++)
      System.out.print(a[i]+"\t");

      for(i=0,j=n-1;i<n/2;i++,j--)
      {temp=a[i];
       a[i]=a[j];
       a[j]=temp;
       }
       
     System.out.println("\nThe array in reverse order is ");
     for(i=0;i<n;i++)
     System.out.print(a[i]+"\t");

    }

    }

import java.io.*;
import java.util.*;

class linear
{  public static void main(String args[])
   { int i,x,n,k=0;
     int a[]=new int[10];
     Scanner s=new Scanner(System.in);

     System.out.println("Enter no. of elements ");
     n=s.nextInt();

     System.out.println("\nEnter elements ");

     for(i=0;i<n;i++)
     a[i]=s.nextInt();
      
     System.out.println("\n\nThe array is ");
     for(i=0;i<n;i++)
     System.out.println(a[i]+"\t");

    System.out.println("\n\nEnter element to be found ");
    x=s.nextInt();

    for(i=0;i<n;i++)
    if(a[i]==x)
    { System.out.println("\nElement found ");
      k=1;
      break; 
     }

    if(k==0)
    System.out.println("\nElement not found ");
    }
    }
     

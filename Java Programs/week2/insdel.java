import java.io.*;
import java.util.*;

class insdel
{ 
   public static void main(String args[])
   { int n,i,x,k;
     int a[]=new int[20];
     Scanner s=new Scanner(System.in);
     
     System.out.println("Enter no. of elements ");
     n=s.nextInt();

     System.out.println("Enter elements ");
     for(i=0;i<n;i++)
     a[i]=s.nextInt();

    System.out.println("The array is \n");
    for(i=0;i<n;i++)
    System.out.print(a[i]+"\t");

    System.out.println("\nEnter position at which element is to be inserted ");
    k=s.nextInt();

    System.out.println("\nEnter element ");
    x=s.nextInt();

    for(i=n-1;i>=k-1;i--)
      a[i+1]=a[i];
    
    a[k-1]=x;
    n=n+1;

    System.out.println("\n\nThe array is \n");
    for(i=0;i<n;i++)
    System.out.print(a[i]+"\t");

    System.out.println("\n\nEnter position of element to be deleted ");
    k=s.nextInt();

    for(i=k-1;i<n;i++)
    a[i]=a[i+1];

    n=n-1; 

    System.out.println("\nThe array is \n");
    for(i=0;i<n;i++)
    System.out.print(a[i]+"\t"); 
   
  
 }

  }

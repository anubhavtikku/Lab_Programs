import java.io.*;
import java.util.*;

class bubble
{ 
  public static void main(String args[])
  { int i,j,n,temp;
    int a[]=new int[20];
    Scanner s=new Scanner(System.in);
    
    System.out.println("Enter no. of elements ");
    n=s.nextInt();

    System.out.println("Enter elements ");
    for(i=0;i<n;i++)
    a[i]=s.nextInt();
         
    System.out.println("\nElements in ascending order are ");
    
    for(j=n-1;j>0;j--)
    for(i=0;i<j;i++)
    if(a[i]>a[i+1])
    { temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
     }
     
   for(i=0;i<n;i++)
   System.out.println(a[i]+"\t");

   System.out.println("\nElements in descending order are ");
    
    for(j=n-1;j>0;j--)
    for(i=0;i<j;i++)
    if(a[i]<a[i+1])
    { temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
     }
     
   for(i=0;i<n;i++)
   System.out.println(a[i]+"\t");
 
    

   }

   }
    


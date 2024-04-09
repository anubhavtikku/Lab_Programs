import java.io.*;
import java.util.*;

class symmetric
{ public static void main(String args[])
  { int i,j,n,k=0;
    int a[][]=new int[10][10];
    Scanner s=new Scanner(System.in);

   System.out.println("Enter dimension of square matrix ");
   n=s.nextInt();

   System.out.println("\nEnter elements in matrix ");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   a[i][j]=s.nextInt();

   System.out.println("\nThe matrix is ");   
   for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
     System.out.print(a[i][j]+"\t");
     System.out.print("\n");
     }

   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   if(a[i][j]!=a[j][i])
   k=1;
   
  if(k==0)
  System.out.println("\nSymmetric Matrix ");

  else 
  System.out.println("\nNon Symmetric Matrix ");
  
   } 
  
  }

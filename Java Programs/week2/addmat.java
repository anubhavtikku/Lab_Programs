import java.io.*;
import java.util.*;

class addmat
{ public static void main(String args[])
   { int i,j,m,n;
     int a[][]=new int[10][10];
     int b[][]=new int[10][10];
     int c[][]=new int[10][10];
     Scanner s=new Scanner(System.in);
     
     System.out.println("Enter two dimensions of the matrix ");
     m=s.nextInt();
     n=s.nextInt();

     System.out.println("\nEnter elements of first matrix ");
   
     for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     a[i][j]=s.nextInt();
    
     System.out.println("\n\nEnter elements of second matrix ");
   
     for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     b[i][j]=s.nextInt();

                           
     for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     c[i][j]=a[i][j]+b[i][j];

     System.out.println("\n\nThe resultant matrix is ");   
     for(i=0;i<m;i++)
     { for(j=0;j<n;j++)
       System.out.print(c[i][j]+"\t");
       System.out.print("\n");
       }

       }
     }

      

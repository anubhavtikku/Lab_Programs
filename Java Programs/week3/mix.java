import java.io.*;
import java.util.*;

class mixer
{int a[]=new int[20] ;
 int n;

 void accept()
 {Scanner s=new Scanner(System.in);
  System.out.println("Enter the no. of elements of array ");
  n=s.nextInt();
  int i;
  System.out.println("Enter elements ");
  for(i=0;i<n;i++)
  a[i]=s.nextInt();
  }

 mixer mix(mixer x)
{mixer c=new mixer();
 int temp,k,i;
 for(i=0;i<x.n;i++)
 c.a[i]=x.a[i];

 for(i=x.n,k=0;i<(x.n+this.n);i++,k++)
 c.a[i]=this.a[k];
 int j= x.n+this.n;
 c.n=j;

 for(i=0;i<j;i++)
 for(k=0;k<j-i-1;k++)
 if(c.a[k]>c.a[k+1])
 { temp=c.a[k];
   c.a[k]=c.a[k+1];
   c.a[k+1]=temp;
 }

for(i=0;i<c.n-1;i++)
 if(c.a[i]==c.a[i+1])
 { for(j=i;j<(c.n-1);j++)
   c.a[j]=c.a[j+1];
   c.n=c.n-1;
   i=i-1;
 }

 return c;
 }

 void display()
 { int i;
   System.out.print("The elements in array are ");
   for(i=0;i<n;i++)
   System.out.print(a[i]+"\t");
  }
  };

class mix
{ public static void main(String args[])
   { mixer m1=new mixer();
     mixer m2=new mixer();
     mixer m3=new mixer();
     m1.accept();
     m2.accept();
     m3=m1.mix(m2);
     m3.display();
    }
}
             

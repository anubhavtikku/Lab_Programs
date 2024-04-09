package mypackages.p1;
import java.io.*;

public class Max
{ public static int max(int i,int j,int k)
  { if((i>=j)&&(i>=k))
    return i;
    if((j>=i)&&(j>=k))
    return j;
    if((k>=i)&&(k>=j))
    return k;
    return 0;
   }

  public static float max(float i,float j,float k)
  { if((i>=j)&&(i>=k))
    return i;
    if((j>=i)&&(j>=k))
    return j;
    if((k>=i)&&(k>=j))
    return k;
    return 0;
   }

  public static int max(int a[],int n)
  { int i,max=a[0];
    for(i=0;i<n;i++)
    if(a[i]>max)
    max=a[i];     
    return max;
  }

  public static int max(int a[][],int m,int n)
  { int i,j,max=a[0][0];
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    if(a[i][j]>max)
    max=a[i][j];     
    return max;
  }

  };

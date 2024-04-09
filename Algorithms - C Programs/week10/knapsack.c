#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{if(a>b)
return a;

return b;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[100][100]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 

int main()
{ int val[100];
  int wt[100];
  

  warshall(a,n);

 printf("\nThe matrix is\n");


}

import java.io.*;
import java.util.*;

class card
{ int rank;
  char suit;
 
 card(int r,char s)
 { rank=r;
   suit=s;
 }

 int getrank()
 {
   return rank;
 }

 char getsuit()
 {
   return suit;
 }
 
 };

class cardtester
{ public static void main(String args[])
  { card a[]=new card[5];
    Scanner s=new Scanner(System.in);
    int i,j,x,k1,k2,l=0;
    int b[]=new int[5];
    char y;
    for(i=0;i<5;i++)
    { System.out.println("Enter the rank and suit of card ");
      x=s.nextInt();
      y=s.next().charAt(0);
      a[i]=new card(x,y);
     }
  
   for(i=0;i<5;i++)
   { b[i]=a[i].getrank();
     }


   for(i=0;i<5;i++)
   {k1=0 ;
    for(j=i+1;j<5;j++)
    if((b[i]==b[j])&&(b[i]!=0))
      { b[j]=0;
        k1++;
       }
   if ((k1==2)||(k1==1))   
     l=l+1;  }

   
  if(l==2)
   System.out.println("Full House ");

  for(i=0;i<5;i++)
  { x=a[i].getrank();
    y=a[i].getsuit();
    System.out.println("Card"+(i+1)+" Rank-"+x+" Suit-"+y);
   }
}
}

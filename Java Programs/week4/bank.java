import java.io.*;
import java.util.*;

class bankaccount
{ String name;
  int acno;
  int type;
  int balance;
  static int rate;
 
 bankaccount()
 { acno=0;
   balance=0;
   type=1;
   rate=5;
  }

 bankaccount(String n,int t,int a,int b)
 { name=n;
   type=t;
   acno=a;
   balance=b;
  }

 bankaccount(bankaccount a)
 { name=a.name;
   type=a.type;
   acno=a.acno;
   balance=a.balance;
  }

void deposit(int d)
{balance=balance+d; }


void with(int a)
{ if(balance>a)
   {balance=balance-a;
    System.out.println("Withdrawal Successful ");
    }
   else 
   System.out.println("Balance Insufficient ");
}

void disp()
{ System.out.println("Account No. "+acno+" Name "+name+" Type "+type );
  System.out.println("Balance "+balance+" Rate "+rate);
}

};

class bank
{ public static void main(String args[])
  { bankaccount a=new bankaccount();
    a=new bankaccount("Anubhav",1,20,0);
    int d;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter amount to be deposited in account ");
    d=s.nextInt();
    a.deposit(d);
    System.out.println("Enter amount to be withdrawn ");
    d=s.nextInt();
    a.with(d);
    System.out.println("Account Details are ");
    a.disp();
   }
}

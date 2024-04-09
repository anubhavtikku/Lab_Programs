import java.util.Scanner;
class Bank{
	String name,type;
	long accno;
	double balance;
	static double rate=4.0;
	Bank(){
		name="";
		type="";
		accno=0;
		balance=0.0;
		System.out.println("In default constructor");
	}
	Bank(String name,long accno,String type, double balance){
		this.name=name;
		this.accno=accno;
		this.type=type;
		this.balance=balance;
	}
	Bank(Bank ob){
		name=ob.name;
		type=ob.type;
		accno=ob.accno;
		balance=ob.balance;
	}
	void deposit(double amt){
		balance+=amt;
	}
	void withdraw(double amt){
		if(balance<amt){
			System.out.println("Insufficient Balance");
			return;
		}
		balance-=amt;
	}
	void display(){
		System.out.println("Name:"+name+"\nAcc No:"+accno+"\nType of account:"+type+"\nBalance:Rs. "+balance);
	}
	static void displayRate(){
		System.out.println("Rate of interest is "+rate+"%");
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the details of acount:");
		System.out.print("Name:");
		String name=sc.nextLine();
		System.out.print("Type of Account:");
		String type=sc.nextLine();
		System.out.print("Account Number:");
		long accno=sc.nextLong();
		System.out.println("Enter current balance:");
		double balance=sc.nextDouble();
		Bank ob1=new Bank();
		Bank ob=new Bank(name,accno,type,balance);
		Bank ob2=new Bank(ob);
		while(true){
			System.out.println("1. Deposit 2. Withdraw 3. Display 4. Show ROI 5. Exit");
			switch(sc.nextInt()){
				case 1:System.out.println("Enter amount");
				ob.deposit(sc.nextDouble());
				break;
				case 2:System.out.println("Enter amount");
				ob.withdraw(sc.nextDouble());
				break;
				case 3:ob.display();
				break;
				case 4:Bank.displayRate();
				break;
				case 5:return;
			}
		}
	}
}
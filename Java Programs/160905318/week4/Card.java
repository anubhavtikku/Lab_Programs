import java.util.Scanner;
class Card{
	private int rank;
	private char suit;
	Card(int rank,char suit){
		this.rank=rank;
		this.suit=suit;
	}
	char getSuit(){	return suit; }
	int getRank(){ return rank; }
}
class CardTester{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Card cards[]=new Card[5];
		int freq[]=new int[13];
		for(int i=0;i<5;i++){
			System.out.print("Card "+(i+1)+" rank:");
			int r=sc.nextInt();
			System.out.print("Card "+(i+1)+" suit:");
			char c=Character.toUpperCase(sc.next().charAt(0));
			if(r<1 || r>13 || "SCHDschd".indexOf(c)<0){
				System.out.println("Not a valid card");
				i--;
				continue;
			}
			cards[i]=new Card(r,c);
			freq[r-1]++;
		}
		boolean two=false;
		boolean three=false;
		for(int i=0;i<13;i++){
			if(freq[i]==2)
				two=true;
			if(freq[i]==3)
				three=true;
		}
		System.out.println((two && three?"Full House":"Not a Full House"));
		for(int i=0;i<5;i++){
			System.out.println("Card "+i+" Rank: "+cards[i].getRank()+" Suit: "+cards[i].getSuit());
		}
	}
}
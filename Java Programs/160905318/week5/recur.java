import java.util.Scanner;
class Recur{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter main string");
		char ch[]=sc.nextLine().toCharArray();
		System.out.println("Enter searching string");
		char se[]=sc.nextLine().toCharArray();
		int count=0;
		for(int i=0;i<ch.length-se.length+1;i++){
			int j;
			for(j=0;j<se.length;j++){
				if(ch[i+j]!=se[j])
					break;
			}
			if(j==se.length){
				count++;
				System.out.println("Found at index "+i);
			}
		}
		System.out.println("Found total "+count+" occurances");
	}
}
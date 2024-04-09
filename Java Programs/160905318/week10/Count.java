import java.io.*;
import java.util.*;
class Count{
	public static void main(String args[])throws Exception{
		File f=new File("fileNames.txt");
		Scanner sc=new Scanner(f);
		long count[]=new long[4];
		while(sc.hasNextLine()){
			char ch[]=sc.nextLine().toCharArray();
			count[3]++;
			char prev='\0';
			for(char c:ch){
				count[0]++;
				// System.out.println("Character: "+ c);
				if(Character.isDigit(c) && !Character.isDigit(prev))
					count[1]++;
				if(Character.isLetter(c) && !Character.isLetter(prev))
					count[2]++;
				// debug(count);
				prev=c;
			}
		}
		System.out.println("Characters:"+count[0]+"\nNumbers:"+count[1]+"\nWords:"+count[2]+"\nLines:"+count[3]);
	}
	static void debug(long count[]){
		System.out.println("Characters:"+count[0]+"\nNumbers:"+count[1]+"\nWords:"+count[2]+"\nLines:"+count[3]);
		System.out.println();
	}
}
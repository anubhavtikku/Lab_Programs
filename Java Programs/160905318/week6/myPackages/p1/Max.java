package myPackages.p1;
public class Max{
	public static int max(int a,int b,int c){
		return Math.max(Math.max(a,b),c);
	}
	public static float max(float a,float b,float c){
		return Math.max(Math.max(a,b),c);
	}
	public static int max(int a[]){
		int max=a[0];
		for(int i:a){
			if(i>max)
				max=i;
		}
		return max;
	}
	public static int max(int a[][]){
		int max=a[0][0];
		for(int[] i:a){
			int c=max(i);
			if(c>max)
				max=c;
		}
		return max;
	}
}
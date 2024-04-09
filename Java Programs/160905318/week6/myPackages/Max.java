package p1;
class Max{
	static int max(int a,int b,int c){
		return Math.max(Math.max(a,b),c);
	}
	static float max(float a,float b,float c){
		return Math.max(Math.max(a,b),c);
	}
	static int max(int a[]){
		int max=a[0];
		for(int i:a){
			if(i>max)
				return max;
		}
		return max;
	}
	static int max(int a[][]){
		int max=a[0][0];
		for(int[] i:a){
			for(int j:i){
				if(j>max)
					max=j;
			}
		}
		return max;
	}
}
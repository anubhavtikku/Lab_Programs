class List<T>{
	T a[];
	int c;
	List(){
		@SuppressWarnings("unchecked")
		a=(T[]) new Object[100];
		c=0;
	}
	List(int n){
		@SuppressWarnings("unchecked")
		a=(T[]) new Object(n);
		c=0;
	}
	void add(T n){
		if(c==a.length){
			@SuppressWarnings("unchecked")
			T b[]=(T[]) new Object[c+100];
			for(int i=0;i<c;i++){
				b[i]=a[i];
			}
			a=b;
		}
		a[c++]=n;
	}
	T get(int n){
		return a[n];
	}
}

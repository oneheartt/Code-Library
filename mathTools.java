public class mathTools{
	public static boolean checkPrime(long x){
		for(int i = 2; 1l * i * i <= x; ++i){
			if(x % i == 0) return false;
		}
		return x > 1;
	}
	public static long mypow(long x, long y){
		long res = 1;
		while(y > 0){
			if(y % 2 == 1) res = res * x;
			x = x * x;
			y = y / 2;
		}
		return res;
	}
}
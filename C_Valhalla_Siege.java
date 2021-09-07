import java.util.*;
 
public class C_Valhalla_Siege {
	
	public static void main (String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		long n = sc.nextLong();
		long q = sc.nextLong();
		
		long warPow[] = new long[(int)n];
		long arrThrow[] = new long[(int)q];
		
		for(int i = 0; i < n; i++) {
			warPow[i] = sc.nextLong();
		}
		
		for(int i = 0; i < q; i++) {
			arrThrow[i] = sc.nextLong();
		}
		
		long sumArr[] = new long[(int)n+1];
		sumArr[0] = 0;
		
		for(int i = 1; i <= n; i++) {
			sumArr[i] = warPow[i-1] + sumArr[i-1]; 
		}
		sc.close();
		long res = 0;
		long key = 0;
		
		for(int i = 0; i<q; i++) {
			key += arrThrow[i];
			long start = res;
			long end = n;
			
			while(start <= end) {
				long mid = start + (end - start)/2;
				if(key >= sumArr[(int)mid]) {
					res = mid;
					start = mid+1;
				}else {
					end = mid-1;
				}
			}
			
			if(res == n) {
				System.out.println(n);
				key = 0;
				res = 0;
			}else {
				System.out.println(n - res);
			}
			
		}
	}
	
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;
 
public class BShubhamMathWork {
 
    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n;
                long m;
                n=fs.nextInt();
                m=fs.nextLong();
                long arr[]=fs.readArray(n);
                long total=0;
                Arrays.sort(arr);
                total+=n+2*(arr[n-1]);
                for(int i=1;i<n-1;i++) {
                    total+=arr[i];
                }
                //System.out.println(total);
                if(total<=m) System.out.println("YES");
                else System.out.println("NO");
            }
        }
        catch (Exception e) {
            return;
        }
    }
 
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
 
        String next() {
            while (!st.hasMoreTokens())
                try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long[] readArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
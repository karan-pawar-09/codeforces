
/*
    author:Karan
    created:27.03.2022 12:26:37
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class B__Mex {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = 1;
            for (int tt = 0; tt < T; tt++) {
                int n = fs.nextInt();
                int arr[] = fs.readArray(n);
                HashSet<Integer> s = new HashSet<Integer>();
                for (int i = 0; i <= 2000; i++) {
                    s.add(i);
                }
                for (int i = 0; i < n; i++) {
                    s.remove(arr[i]);
                }
                int mini = (int) 1e9;
                for (int x : s) {
                    mini = Math.min(mini, x);
                }
                ArrayList<Long> ar = new ArrayList<Long>();
                
                System.out.println(mini);
            }
        } catch (Exception e) {
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
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}

/*
    author:Karan
    created:27.03.2022 12:32:15
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class C__Choose_Elements {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = 1;
            for (int tt = 0; tt < T; tt++) {
                int n, k;
                n = fs.nextInt();
                k = fs.nextInt();
                int a[] = fs.readArray(n);
                int b[] = fs.readArray(n);
                boolean dp[][] = new boolean[n][2];
                for (int i = 0; i < n; i++) {
                    dp[i][1] = dp[i][0] = false;
                }
                dp[0][0] = true;
                dp[0][1] = true;
                for (int i = 1; i < n; i++) {
                    if (dp[i - 1][0]) {
                        if (Math.abs(a[i - 1] - a[i]) <= k) {
                            dp[i][0] = true;
                        }
                        if (Math.abs(a[i - 1] - b[i]) <= k) {
                            dp[i][1] = true;
                        }
                    }
                    if (dp[i - 1][1]) {
                        if (Math.abs(b[i - 1] - a[i]) <= k) {
                            dp[i][0] = true;
                        }
                        if (Math.abs(b[i - 1] - b[i]) <= k) {
                            dp[i][1] = true;
                        }
                    }
                }
                if (dp[n - 1][0] || dp[n - 1][1]) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
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
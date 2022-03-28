
/*
    author:Karan
    created:28.03.2022 00:11:08
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class D__Polynomial_division {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            long T = 1;
            for (long tt = 0; tt < T; tt++) {
                int n = fs.nextInt();
                int m = fs.nextInt();
                long a[] = fs.readArray(n + 1);
                long c[] = fs.readArray(n + m + 1);
                long b[] = new long[m + 1];
                for (int i = m; i >=0; i--) {
                    b[i] = c[i+n] / a[n];
                    for (int j = 0; j <= n; j++) {
                        c[j + i] -= b[i] * a[j];
                    }
                }
                for (long x : b) {
                    System.out.print(x + " ");
                }
                System.out.println("");
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

        long[] readArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
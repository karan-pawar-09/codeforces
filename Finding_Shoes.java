
/*
    author:Karan
    created:30.03.2022 21:53:00
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Finding_Shoes {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n, m;
                n = fs.nextInt();
                m = fs.nextInt();
                int ones = Math.min(n, m);
                int two = Math.max(0, n - m);
                System.out.println(ones + 2 * two);
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
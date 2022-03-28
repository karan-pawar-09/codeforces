
/*
    author:Karan
    created:27.03.2022 12:17:40
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

class AGood_morning {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = 1;
            // int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int a, b, c, d;
                a = fs.nextInt();
                b = fs.nextInt();
                c = fs.nextInt();
                d = fs.nextInt();
                Boolean answer = ans(a, b, c, d);
                if (answer)
                    System.out.println("Takahashi");
                else
                    System.out.println("Aoki");
            }
        } catch (Exception e) {
            return;
        }
    }

    static Boolean ans(int a, int b, int c, int d) {
        if (a < c)
            return true;
        else {
            if (a == c) {
                if (b <= d)
                    return true;
            }
        }
        return false;
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
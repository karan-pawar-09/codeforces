
/*
    author:Karan
    created:27.03.2022 22:33:38
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class B_Marin_and_Anticoprime_Permutation {
    static long mod = 998244353;

    static long mul(long a, long b) {
        return (a * b) % mod;
    }

    static long fact[] = new long[(int) 1e4];

    static void pre() {
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < (int) 1e4; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            pre();
            FastScanner fs = new FastScanner();
            long T = fs.nextInt();
            for (long tt = 0; tt < T; tt++) {
                long n;
                n = fs.nextInt();
                if (n % 2 == 1) {
                    System.out.println(0);
                } else {
                    System.out.println(mul(fact[(int) n / 2], fact[(int) n / 2]));
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


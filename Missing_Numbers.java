
/*
    author:Karan
    created:26.03.2022 10:53:30
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Missing_Numbers {
    static Integer A, B, C, D;

    static HashMap<Character, Integer> M = new HashMap<>();
    static HashMap<Character, Boolean> used = new HashMap<>();

    static Boolean calc(String s) {
        long add = M.get(s.charAt(0));
        long mul = M.get(s.charAt(1));
        long sub = M.get(s.charAt(2));
        long div = M.get(s.charAt(3));
        // System.out.println(sum + " " + mul + " " + sub + " " + div);
        long a = (add + sub) / 2;
        long b = (add - sub) / 2;
        // cout << a << " " << b << endl;
        if (a >= 1 && a <= 10000 && b >= 1 && b <= 10000 && mul == a * b && (div == a / b)) {
            x = a;
            y = b;
            return true;
        }
        return false;
    }

    static boolean ans;
    static long x, y;

    static String arr[] = new String[] { "ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA",
            "BDAC", "BDCA", "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB", "DBAC", "DBCA", "DCAB",
            "DCBA" };

    static void solve() {
        for (String x : arr) {
            ans |= calc(x);
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            long T = fs.nextInt();
            for (long tt = 0; tt < T; tt++) {
                x = -1;
                y = -1;
                ans = false;
                A = fs.nextInt();
                B = fs.nextInt();
                C = fs.nextInt();
                D = fs.nextInt();
                M.clear();
                used.clear();
                for (char i = 'A'; i <= 'D'; i++) {
                    used.put(i, false);
                }
                M.put('A', A);
                M.put('B', B);
                M.put('C', C);
                M.put('D', D);
                solve();
                System.out.println(x + " " + y);
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



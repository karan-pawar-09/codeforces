
/*
    author:Karan
    created:25.03.2022 23:01:37
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Permute {
    static HashMap<Character, Boolean> used = new HashMap<>();

    static void solve(String S, int a) {
        if (S.length() == 4) {
            System.out.print("\"");
            System.out.print(S);
            System.out.print("\"");
            System.out.print(", ");
            return;
        }
        for (char i = 'A'; i <= 'D'; i++) {
            if (!used.get(i)) {
                used.replace(i, true);
                solve(S + i, a);
                used.replace(i, false);
            }
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int T = fs.nextInt();
        for (int tt = 0; tt < T; tt++) {
            used.clear();
            for (char i = 'A'; i <= 'D'; i++) {
                used.put(i, false);
            }
            solve("", 1);
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

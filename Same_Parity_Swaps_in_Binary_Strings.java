
/*
    author:Karan
    created:26.03.2022 11:00:01
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Same_Parity_Swaps_in_Binary_Strings {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n = fs.nextInt();
                String s = fs.next();
                int odd0 = 0;
                int odd1 = 0;
                int even0 = 0;
                int even1 = 0;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0) {
                        int p = (s.charAt(i) == '0') ? even0++ : even1++;
                    } else {
                        int q = (s.charAt(i) == '0') ? odd0++ : odd1++;
                    }
                }
                System.out.println(Math.min(even0, odd1) + Math.min(odd0, even1));

            }
        } catch (Exception e) {
            return;
        }
    }

    public static void reverse(char[] array) {
        int n = array.length;
        for (int i = 0; i < n / 2; i++) {
            char temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
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
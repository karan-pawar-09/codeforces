/*
    author:Karan
    created:30.03.2022 22:24:20
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Maximize_the_Minimum {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n,k;
                n=fs.nextInt();
                k=fs.nextInt();
                int arr[] = fs.readArray(n);
                Arrays.sort(arr);
                if(k>=n-1) {
                    System.out.println(arr[n-1]);
                } else {
                    System.out.println(arr[k]);
                }
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
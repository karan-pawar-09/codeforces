
/*
    author:Karan
    created:30.03.2022 22:05:39
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Flip_Sorting {

    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n;
                n = fs.nextInt();
                String s;
                s = fs.next();
                ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
                int count = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if ((s.charAt(i) == '0' && count % 2 == 0) || (count % 2 == 1 && s.charAt(i) == '1')) {
                        ArrayList<Integer> ar = new ArrayList<Integer>();
                        ar.add(1);
                        ar.add(i + 1);
                        arr.add(ar);
                        count++;
                    }
                }
                System.out.println(arr.size());

                for (ArrayList x : arr) {
                    for(int i=0;i<x.size();i++) {
                        System.out.print(x.get(i)+" ");
                    }
                    System.out.println("");
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
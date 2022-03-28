/*
    author:Karan
    created:24.03.2022 20:31:05
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.*;

public class B_Subtract_Operation {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int T = fs.nextInt();
        for (int tt = 0; tt < T; tt++) {
            int n,k;
            n=fs.nextInt();
            k=fs.nextInt();
            int arr[]=new int[n];
            for(int i=0;i<n;i++) {
                arr[i]=fs.nextInt();
            }
            HashMap<Integer ,Boolean> M = new HashMap<>();
            for(int i=0;i<n;i++) {
                M.put(arr[i],true);
            }
            boolean ans=false;
            for(int i=0;i<n;i++) {
                if(M.containsKey((arr[i]+k))==true) {
                    ans=true;
                }
            }
            if(ans==true) {
                System.out.println("YES");
            } else {
               System.out.println("NO");
            }

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
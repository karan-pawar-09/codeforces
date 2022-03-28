/*
    author:Karan
    created:24.03.2022 20:13:29
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A_Good_Pairs {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int T = fs.nextInt();
        for (int tt = 0; tt < T; tt++) {
            int n;
            n=fs.nextInt();
            int arr[]=new int[n];
            for(int i=0;i<n;i++) {
                arr[i]=fs.nextInt();
            }
            int one=0;
            int maxi=arr[0];
            for(int i=0;i<n;i++) {
                if(arr[i]<maxi) {
                    maxi=arr[i];
                    one=i;
                }
            }
            int two=0;
            maxi=arr[0];
            for(int i=0;i<n;i++) {
                if(arr[i]>maxi) {
                    maxi=arr[i];
                    two=i;
                }
            }
            System.out.println((one+1)+" "+(two+1));
           
            
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
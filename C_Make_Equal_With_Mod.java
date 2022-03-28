/*
    author:Karan
    created:24.03.2022 20:59:30
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Arrays;

public class C_Make_Equal_With_Mod {

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int T = fs.nextInt();
        for (int tt = 0; tt < T; tt++) {
            int n=fs.nextInt();
            int[] arr=new int[n];
            int one=0;
            for(int i=0;i<n;i++) {
                arr[i]=fs.nextInt();
                if(arr[i]==1) {
                    one++;
                }
            }
            if((one==0) || (one==n)) {
                System.out.println("YES");
            } else {
                Arrays.sort(arr);
                boolean ans=true;
                for(int i=1;i<n;i++) {
                    if((arr[i]-arr[i-1])==1) {
                        ans=false;
                    }
                }
                if(ans) {
                    System.out.println("YES");
                }
                else {
                    System.out.println("NO");
                }
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
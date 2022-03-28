
/*
    author:Karan
    created:27.03.2022 21:37:57
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class A_Marin_and_Photoshoot {
    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int n;
                n = fs.nextInt();
                String s;
                s = fs.next();
                int ans=0;
                for(int i=1;i<n;i++) {
                    if(s.charAt(i)=='0' && s.charAt(i-1)=='0') {
                        ans+=2;
                    }
                    else if(i>1 && s.charAt(i)=='0' && s.charAt(i-2)=='0') {
                        ans++;
                    }
                }
                System.out.println(ans);

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

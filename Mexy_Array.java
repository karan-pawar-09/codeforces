
/*
    author:Karan
    created:25.03.2022 11:01:15
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.*;

public class Mexy_Array {
    public static void main(String[] args) throws IOException {
        try {
            FastScanner fs = new FastScanner();
            int T = fs.nextInt();
            for (int tt = 0; tt < T; tt++) {
                boolean ans = true;
                int n = fs.nextInt();
                int arr[] = new int[n];
                ArrayList<Integer> b = new ArrayList<Integer>();
                Set<Integer> s = new HashSet<Integer>();
                Set<Integer> not = new HashSet<Integer>();
                for (int i = 0; i < n; i++) {
                    arr[i] = fs.nextInt();
                    if (arr[i] > (i + 1)) {
                        ans = false;
                    }
                    if (arr[i] != -1) {
                        b.add(arr[i]);
                        s.add(arr[i]);
                    }
                }
                for (int i = 1; i < b.size(); i++) {
                    if (b.get(i) < b.get((i - 1))) {
                        ans = false;
                    }
                }
                if (ans) {
                    for (int i = 0; i <= 2 * n + 10; i++) {
                        if (!s.contains(i)) {
                            not.add(i);
                        }
                    }
                    boolean first = false;
                    ArrayList<Integer> answer = new ArrayList<Integer>();
                    int x[] = new int[s.size()];
                    int y[] = new int[not.size()];
                    int indx = 0;
                    for (int p : s) {
                        x[indx++] = p;
                    }
                    indx = 0;
                    for (int p : not) {
                        y[indx++] = p;
                    }
                    Arrays.sort(x);
                    Arrays.sort(y);
                    int ax = 0;
                    int j = 0;
                    for (int i = 0; i < n; i++) {
                        if (!first || arr[i] == -1) {
                            Integer one = y[j++];
                            answer.add(one);
                            first = true;
                        } else {
                            Integer one = x[ax++];
                            answer.add(one);
                        }
                        if (arr[i] != -1) {
                            first = true;
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        System.out.print(answer.get(i) + " ");
                    }
                    System.out.println("");
                } else {
                    System.out.println(-1);
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
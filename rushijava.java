import java.util.*;

public class rushijava {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        input.close();
        int inf = (int) 1e9 + 10;
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }
        int ans = -inf;
        for (int i = 0; i < n; i++) {
            if(arr[i]!=maxi)
                ans = Math.max(ans, arr[i]);
        }
        System.out.println(ans);
    }
}
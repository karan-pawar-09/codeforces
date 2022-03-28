import java.util.*;

public class tesmppp {
    static int maxSubArraySum(int a[], int size) {
        int max_so_far = a[0];
        int curr_max = a[0];
        for (int i = 1; i < size; i++) {
            curr_max = Math.max(a[i], curr_max+a[i]);
            max_so_far = Math.max(max_so_far, curr_max);
        }
        return max_so_far;
	}
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int n=input.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++) {
            arr[i]=input.nextInt();
        }
        int p=maxSubArraySum(arr,n);
        input.close();
        System.out.println(p);
    }
}
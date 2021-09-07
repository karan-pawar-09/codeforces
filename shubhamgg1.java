import java.util.*;
public class shubhamgg1 {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int a=input.nextInt();
        int b=input.nextInt();
        int n=input.nextInt();
        int[] arr= new int[n];
        int[] ar= new int[n];
        for(int i=0;i<n;i++) {
            arr[i]=input.nextInt();
        }
        for(int i=0;i<n;i++) {
            ar[i]=input.nextInt();
        }
        int[][] dp=new int[n][2];
        int[][] col=new int[n][2];
        for(int i=0;i<n;i++) {
            col[i][0]=col[i][1]=-1;
        }
        dp[0][0]=0;
        dp[0][1]=arr[0]*b;
        col[0][1]=ar[0];
        for(int i=1;i<n;i++) {
            int one=arr[i]*a;
            int two=arr[i]*b;
            if(dp[i-1][0]>dp[i-1][1]) {
                dp[i][0]=dp[i-1][0];
                col[i][0]=col[i-1][0];
            }
            else {
                dp[i][0]=dp[i-1][1];
                col[i][0]=col[i-1][1];
            }
            int t1=0;
            int t2=0;
            if(col[i-1][0]==ar[i]) {
                t1=one;
            }
            else {
                t1=two;
            }
            if(col[i-1][1]==ar[i]) {
                t2=one;
            }
            else {
                t2=two;
            }
            if(dp[i-1][0]+t1<dp[i-1][1]+t2) {
                dp[i][1]=dp[i-1][1]+t2;
                col[i][1]=ar[i];
            }
            else {
                dp[i][1]=dp[i-1][0]+t1;
                col[i][1]=ar[i];
            }
        }
        input.close();
        System.out.println(Math.max(dp[n-1][0],dp[n-1][1]));
    }
}
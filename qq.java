import java.text.DecimalFormat;
import java.util.*;
 
class qq
{
 
static public double avgDiff(int input1,int[] input2)
{
    int x=0;
    for(int i=0;i<input1;i++) {
        x+=input2[i];
    }
    boolean dp[]=new boolean[x+1];
    for(int i=0;i<=x;i++) {
        dp[i]=false;
    }
    dp[0]=true;
    for(int i=0;i<input1;i++) {
        for(int j=x;j>=1;j--) {
            if(j-input2[i]>=0) {
                dp[j]=dp[j]|dp[j-input2[i]];
            }
        }
    }
    double a=0;
    double b=0;
    for(int i=1;i<x;i++) {
        if(dp[i]) {
            a+=Math.abs(x-2*i);
            b++;
        }
    }   
    
    double ans=a/b;   
    ans=(double)Math.round(ans*1000000)/1000000;
    return ans;
}
 
// Driver Code
public static void main(String[] args)
{
    Scanner input = new Scanner(System.in);
    int input1=input.nextInt();
    int input2[]=new int[input1];
    for(int i=0;i<input1;i++) {
        input2[i]=input.nextInt();
    }
   double ans=avgDiff(input1, input2);
   System.out.println(ans);
    input.close();
}
}

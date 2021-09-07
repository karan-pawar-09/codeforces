import java.util.*;
public class shubhamgg {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int a=input.nextInt();
        int b=input.nextInt();
        int n=input.nextInt();

        int ans=1000000000;
        for(int i=0;i<=n;i++) {
            ans=Math.min(ans,Math.max(i*a,(n-i)*b));
        }
        input.close();
        
        System.out.println(ans);
        
    }
}
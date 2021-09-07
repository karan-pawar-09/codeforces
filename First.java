import java.util.*;
public class First {
    static int ans (int a) {
        int ans=1;
        int c=1;
        int b=1;
        if(a==1||a==2) {
            return 1;
        }
        for(int i=2;i<a;i++) {
            ans=(b%10+c%10)%10;
            b=c%10;;
            c=ans%10;
        }
        return ans%10;
    }
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int variable=input.nextInt();
        input.close();
        int answer=ans(variable);
        System.out.println(answer);
    }
}
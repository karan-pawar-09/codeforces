import java.util.*;
public class factorial {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int a=input.nextInt();
        input.close();
        int ans=1;
        for(int i=1;i<=a;i++) {
            ans*=i;
        }
        System.out.println(ans);
    }
}

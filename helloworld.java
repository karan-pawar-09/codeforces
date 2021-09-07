import java.util.*;
public class helloworld {
    static int greater(int a,int b) {
        return a>=b?a:b;
    }
    public static void main (String[] args) {

        Scanner input = new Scanner(System.in);
        int a=input.nextInt();
        int b=input.nextInt();
        input.close();
        int larger=greater(a,b);
        System.out.println(larger);
    }
}
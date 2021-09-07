import java.util.*;
public class Biggestpalindrome {
    static void palindrome(String s) {
        int maxLength = 1, start = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int flag = 1;
                for (int k = 0; k < (j - i + 1) / 2; k++)
                    if (s.charAt(i + k) != s.charAt(j - k))
                        flag = 0;
                if (flag!=0 && (j - i + 1) > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        for(int i=start;i<=start+maxLength-1;i++) {
            System.out.print(s.charAt(i));
        } 
        System.out.println("\n");
    } 
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        String s=input.next();
        input.close();
        palindrome(s);
    }
}

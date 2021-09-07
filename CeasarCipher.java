import java.util.*;
public class CeasarCipher {
    public static void main (String[] args) {
        Scanner input=  new Scanner(System.in);
        String s = input.nextLine();
        input.close();
        int n=s.length();
        String ans=new String();
        for(int i=0;i<n;i++) {
            if((int)s.charAt(i)>=65&&(int)s.charAt(i)<=90) {               
                ans+=(char)(65+((int)s.charAt(i)-42)%26);
            }
            else if((int)s.charAt(i)>=97&&(int)s.charAt(i)<=122){                
                ans+=(char)(97+((int)s.charAt(i)-74)%26);
            }
            else {
                ans+=s.charAt(i);
            }
        }
        System.out.println(ans);
   }
}
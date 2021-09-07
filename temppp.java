import java.util.*;
public class temppp {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int q=input.nextInt();
        for(int zzz=0;zzz<q;zzz++) {
            String s=input.nextLine();
            String t=input.nextLine();
            int n=s.length();
            int m=t.length();
            Boolean ans=false;
            int j=m-1;
            int i=n-1;
            while(s.charAt(i)!=t.charAt(j)||((n-i)%2==0)) {
                i--;
            }
            while(i>=0&&j>=0) {
                if(s.charAt(i)==t.charAt(j)) {
                    i=i-1;
                    j=j-1;               
                }
                else {
                    i-=2;
                }
            }
            if(j==-1) ans=true;

            if(ans==true) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
            
        }
        input.close();
    }
}
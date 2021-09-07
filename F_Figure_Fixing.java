import java.io.*;
import java.lang.*;
import java.util.*;

public class F_Figure_Fixing {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        String s=input.nextLine();
        int[] arr= {1,2,3,4,5};
        int[] ans;
        Arrays.sort(arr);

        List<int> arrlist
            = new ArrayList<int>();
        for(int i=0;i<arr.length;i++) {
            if(i%2==0) {
                arrlist.add(arr[i]);
            }
        }
        ans=arrlist.toArray();
        input.close();
        System.out.println(answer);
    }
}


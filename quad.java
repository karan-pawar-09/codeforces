import java.util.*;
public class quad {
    static double[] findRoots(double input1,double input2,double input3) {
        double one=(double)(-input2+Math.sqrt(input2*input2-4*input1*input3))/(2*input1);
        double two=(double)(-input2-Math.sqrt(input2*input2-4*input1*input3))/(2*input1);
        double ans[]=new double[2];
        ans[0]=(double)Math.round((double)(one*1000))/(double)1000;
        ans[1]=(double)Math.round((double)(two*1000))/(double)1000;
        return ans;
    }
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        double a=input.nextDouble();
        double b=input.nextDouble();
        double c=input.nextDouble();
        double ans[]=new double[2];
        ans=findRoots(a,b,c);
        System.out.println(ans[0]);
        System.out.println(ans[1]);
        input.close();
        
    }
}
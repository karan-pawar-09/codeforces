
public class lab1_1 {
    static int sum2nums(int a,int b) {
        return a+b;
    }
    static float sum2nums(float a,float b) {
        return a+b;
    }
    public static void main (String[] args) {
        int a,b;
        float c,d;
        a=3;
        b=4;
        c=(float)4.4;
        d=(float)5.7;
        System.out.println(sum2nums(a, b));
        System.out.println(sum2nums(c, d));
    }
}
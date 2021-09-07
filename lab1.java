
class Arithmetic {
    int calculations(int a,int b) {
        return a+b;
    }
}
class Adder extends Arithmetic {
    // int add(int a,int b) {
    //     return calculations(a, b);
    // }
}
public class lab1 {
    public static void main (String[] args) {

        int a=3;
        int b=4;
        Adder adder = new Adder();
        int ans=adder.calculations(a, b);
        System.out.println(ans);
    }
}
import java.util.*;
class shape {
    void erase() {
        System.out.println("Erased");
    }
}
class circle extends shape {
    void draw() {
        System.out.println("Draw Cirle");
    }
}
class triagle extends shape {
    void draw() {
        System.out.println("Draw Triangle");
    }
}
class square extends shape {
    void draw() {
        System.out.println("Draw Square");
    }
}
public class lab1_2 {
    public static void main (String[] args) {
        triagle tri = new triagle();
        circle ci = new circle();
        square sq=new square();
        sq.draw();
        sq.erase();
        ci.draw();
        ci.erase();
        tri.draw();
        tri.erase();
    }
}
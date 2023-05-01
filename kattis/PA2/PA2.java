import java.util.ArrayList;
import java.util.function.Function;

class PA2 {
    static class A {
        int apply(int x) { return x + 1; };
    }


    public static void main(String[] args) {
        A b = new A() {
            int apply(int x) { return x + 2; }
            double apply2(double zero) { return 0.0; }
        };
        System.out.println(b.apply(0));
    }
}
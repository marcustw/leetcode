import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            try {
                long x = sc.nextLong();
                long y = sc.nextLong();
                System.out.println(Math.abs(x - y));
            } catch (Exception e) {
                break;
            }
        }
    }
}

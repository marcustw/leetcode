import java.util.Scanner;

class TestJuly {

    public static void timetable(int x) {
        for (int i = 1; i < 13; i++) {
            System.out.println(String.format("%d x %d = %d", x, i, x * i));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        timetable(x);
    }

}
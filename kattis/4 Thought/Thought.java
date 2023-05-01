import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

class Thought {
    public static String S = "4 %s 4 %s 4 %s 4 = %d";
    public static String AE = "4 %s 4 %s 4 %s 4";
    public static String DIVIDE = "/"; //0
    public static String TIMES = "*"; //1
    public static String PLUS = "+"; //1
    public static String MINUS = "-"; //3
    public static String[] OPERATORS = {DIVIDE, TIMES, PLUS, MINUS};
    public static HashMap<Integer, String> map = new HashMap<>(); //memoization

    /** Checks if operator is divide or multiple. */
    public static boolean isDM(String op) {
        return op.equals(DIVIDE) || op.equals(TIMES);
    }

    /** Computes basic arithmetic expressions. */
    public static int EV(List<String> exp) {
        if (exp.size() == 3) {
            return OP(Integer.parseInt(exp.get(0)), Integer.parseInt(exp.get(2)), exp.get(1));
        } else {
            List<String> copy = new ArrayList<>(exp);
            for (int i = 1; i < exp.size(); i = i + 2) {
                if (isDM(exp.get(i))) {
                    int res = OP(Integer.parseInt(exp.get(i-1)), Integer.parseInt(exp.get(i+1)), exp.get(i));
                    copy.remove(i);
                    copy.add(i, String.valueOf(res));
                    copy.remove(i+1);
                    copy.remove(i-1);
                    return EV(copy);
                }
            }
            int res = OP(Integer.parseInt(exp.get(0)), Integer.parseInt(exp.get(2)), exp.get(1));
            copy.remove(1);
            copy.add(1, String.valueOf(res));
            copy.remove(2);
            copy.remove(0);
            return EV(copy);
        }
    }

    /** Computes binary arithmetic expression. */
    public static int OP(int a, int b, String op) {
        switch (op) {
            case ("/"):
                return a / b;
            case ("*"):
                return a * b;
            case ("+"):
                return a + b;
            case ("-"):
                return a - b;
            default:
                return a;
        }
    }
  
    /** Creates a map of all values created and it's arithmetic expression. */
    public static void generateMap() {
        for (String op1 : OPERATORS) {
            for (String op2 : OPERATORS) {
                for (String op3 : OPERATORS) {
                    String ae = String.format(AE, op1, op2, op3);
                    int r = EV(Arrays.asList(ae.split(" ")));
                    if (!map.containsKey(r)) {
                        map.put(r, String.format(S, op1, op2, op3, r));
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        generateMap();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int c = sc.nextInt();
            if (map.containsKey(c)) {
                System.out.println(map.get(c));
            } else {
                System.out.println("no solution");
            }
        }
    }
}

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Backspace {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        char[] chars = line.toCharArray();
        Stack<Character> stack = new Stack<Character>();
        for (int i = chars.length-1; i >= 0; i--) {
            stack.push(line.charAt(i));
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.empty()) {
            char c = stack.pop();
            if (c == '<') {
                if (sb.length() > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                }
            } else {
                sb.append(c);
            }
        }
        if (sb.length() > 0) {
            System.out.println(sb.toString());
        }
    }
}

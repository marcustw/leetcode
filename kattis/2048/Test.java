import java.util.Arrays;

public class Test {
public static void q1() {
    for (int i = 0; i < 100; i ++) {
        if (i % 3 == 0 && i % 5 == 0) {
            System.out.println("FizzBuzz");
        } else if (i % 3 == 0) {
            System.out.println("Fizz");
        } else if (i % 5 == 0) {
            System.out.println("Buzz");
        } else {
            System.out.println(i);
        }
    }
}

public static String q2(String s1, String s2) {
    //assuming order does not matter
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s1.length(); i++) {
        char c1 = s1.charAt(i);
        for (int j = 0; j < s2.length(); j ++) {
            char c2 = s2.charAt(j);
            if (c1 == c2) {
                sb.append(c1);
                break;
            }
        }
    }
    return sb.toString();
}

private static int[] q3helper(int[] arr, int i, int j) {
    if (i >= j) {
        return arr;
    } else {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        return q3helper(arr, i + 1, j - 1);
    }
}

public static int[] q3(int[] arr) {
    return q3helper(arr, 0, arr.length - 1);
}



    public static void main(String[] args) {
        Arrays.stream(q3(new int[]{1, 2, 3, 4, 5})).forEach(x -> System.out.println(x));
    }
}

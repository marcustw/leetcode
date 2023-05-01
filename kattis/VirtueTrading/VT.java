import java.math.BigDecimal;
import java.util.*;

class VT {

    static Map<Integer, Integer> dp = new HashMap<>();



    public int solution1(int x) {
        int f0 = 0;
        int f1 = 1;

        while (!(x >= f0 && x <= f1)) {
            int temp = f1;
            f1 = f0 + f1;
            f0 = temp;
        }

        int d1 = x - f0;
        int d2 = f1 - x;

        return Math.min(d1, d2);
    }

    public int solution2(int[] A) {
        int curr = A[0];
        final int MAX = 5000;
        if (curr >= MAX) {
            return 0;
        }
        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i < A.length; i++) {
            arr.add(A[i]);
        }
        arr.sort(Comparator.comparingInt(a -> a));
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            curr += arr.get(i);
            if (curr <= MAX) {
                res ++;
            } else {
                break;
            }
        }
        return res;
    }

    static String divideByTwo(String s) {
        return new BigDecimal(s).divide(new BigDecimal(2)).toString();
    }

    static String integerToBinary(String s) {
        String result = "";
        while (!s.equals("0") && !s.equals("1")) {
            int lastDigit = Character.getNumericValue(s.charAt(s.length()-1));
            result = lastDigit % 2 + result; //if last digit is even prepend 0, otherwise 1
            s = divideByTwo(s);
        }
        return (s + result).replaceAll("^0*", "");
    }

    public String solution3(String S) {
        final String error = "ERROR";
        HashSet<Character> hex = new HashSet<>();
        char[] hexspeak = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'};
        for (char x : hexspeak) {
            hex.add(x);
        }
        String hexadecimal = Long.toHexString(Long.parseLong(S));
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < hexadecimal.length(); i++) {
            char c = hexadecimal.charAt(i);
            if (c == '0') {
                c = 'O';
            }
            if (c == '1') {
                c = 'I';
            }
            if (!hex.contains(c)) {
                return error;
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    public int[] solution4(int[] A) {
        List<Integer> arrA = new ArrayList<>();
        for (int x : A) {
            arrA.add(x);
        }
        while (true) {
            List<Integer> arrB = new ArrayList<>(arrA);
            boolean changed = false;
            for (int i = 1; i < A.length - 1; i++) {
                int front = arrB.get(i - 1);
                int mid = arrB.get(i);
                int back = arrB.get(i + 1);
                if (front > mid && back > mid) {
                    arrA.set(i, mid + 1);
                    changed = true;
                }
                if (front < mid && back < mid) {
                    arrA.set(i, mid - 1);
                    changed = true;
                }
            }
            if (!changed) {
                break;
            }
        }
        for (int i = 1; i < A.length - 1; i++) {
            A[i] = arrA.get(i);
        }
        return A;
    }

    public int solution5(String s) {
        int total = s.length();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            for (int j = i + 1; j < s.length(); j++) {
                char c2 = s.charAt(j);
                if (c2 == c) {
                    total ++;
                } else {
                    break;
                }
            }
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println(integerToBinary("16000"));
    }
}
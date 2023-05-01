import java.util.ArrayList;
import java.util.List;

class Expected {
    static int count1s(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '1') {
                count++;
            }
        }
        return count;
    }

    static boolean has3consecutive(String s) {
        for (int i = 0; i < s.length() - 2; i++) {
            char c1 = s.charAt(i);
            char c2 = s.charAt(i+1);
            char c3 = s.charAt(i+2);
            if (c1 == '1' && c2 == '1' && c3 == '1') {
                return true;
            }
        }
        return false;
    }


    static void countExpected(String s) {
        int consecutiveCount = 0;
        int expected = 0;

        while (s.length() < 10) {
            s += "0";
        }

        for (int i = 0; i < s.length(); i++) {



            char c1 = s.charAt(i);

            if (c1 == '1' && consecutiveCount == 0) {
                expected += 1;
                consecutiveCount = 1;
            } else if (c1 == '1' && consecutiveCount == 1) {
                expected += 2;
                consecutiveCount = 2;
            } else if (c1 == '1' && consecutiveCount == 2) {
                expected += 4;
                consecutiveCount = 0;
            } else if (c1 == '0' && consecutiveCount == 0) {
                expected -= 1;
                consecutiveCount = 0;
            } else if (c1 == '0' && consecutiveCount == 1) {
                expected -= 2;
                consecutiveCount = 0;
            } else if (c1 == '0' && consecutiveCount == 2) {
                expected -= 4;
                consecutiveCount = 0;
            }
        }

        System.out.println(s + " " + expected);
    }

    public static void main(String[] args) {
        List<List<String>> l = new ArrayList<>();
        for (int i = 0; i < 11; i++) {
            l.add(new ArrayList<>());
        }
        for (int i = 0; i < 1024; i++) {
            String b = Integer.toBinaryString(i);
            int counts = count1s(b);
            l.get(counts).add(b);
        }
        double p = 0;

        for (int i = 0; i < 11; i++) {
            int counts = 0;
            int expectedValue = 0;
            int size = l.get(i).size();
            for (String s : l.get(i)) {
                if (!has3consecutive(s)) {
                    counts++;
                }
                countExpected(s);
            }
            p += counts * Math.pow(0.4, i) * Math.pow(0.6, 10 - i);
            System.out.printf("Number of 1s: %d and size: %d, number of 3 consecutive E = %d\n", i, size, counts);
        }
        System.out.println("P = " + p);
    }
}
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class P {
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

    static int[] getArr(String s) {
        int[] arr = new int[10];
        int index = 9;
        int j = s.length() - 1;
        while (j >= 0) {
            if (s.charAt(j) == '1') {
                arr[index] = 1;
            }
            j--;
            index--;
        }
        return arr;
    }

    static int countGain(String s) {
        int count = 0;
        int[] arr = getArr(s);
        int[] bets = new int[10];
        bets[0] = 1;
        for (int i = 0; i < 9; i++) {
            if (arr[i] == 1) {
                bets[i+1] = bets[i] * 2;
                if (bets[i+1] == 8) {
                    bets[i+1] = 1;
                }
            } else {
                bets[i+1] = 1;
            }
        }
        printArr(bets);
        for (int i = 0; i < 10; i++) {
            if (arr[i] == 1) {
                count += bets[i];
            } else {
                count -= bets[i];
            }
        }
        return count;
    }

    static void printArr(int[] arr) {
        String s = "[";
        for (int x : arr) {
            s += x + ",";
        }
        s = s.substring(0, s.length()-1);
        s += "]";
        System.out.println(s);
    }

    static double expectedGain() {
        int top = Integer.MIN_VALUE;
        int bot = Integer.MAX_VALUE;
        Map<Integer, int[]> map = new HashMap<>();
        double count = 0.0;
        for (int i = 0; i < 1024; i++) {
            String s = Integer.toBinaryString(i);
            int gain = countGain(s);
            int num1s = count1s(s);
            if (gain > top) {
                top = gain;
            }
            if (gain < bot) {
                bot = gain;
            }
            count += gain * Math.pow(0.4, num1s) * Math.pow(0.6, 10 - num1s);
            if (map.containsKey(gain)) {
                map.get(gain)[num1s] = map.get(gain)[num1s] + 1;
            } else {
                int[] nums = new int[11];
                nums[num1s] = nums[num1s] + 1;
                map.put(gain, nums);
            }
        }
        System.out.println("LARGEST GAINZ = " + top);
        System.out.println("SMALLEST GAINZ = " + bot);
        for (Integer i : map.keySet()) {
            printArr(map.get(i));
            System.out.printf("Gain = %d, \n", i);
        }
        return count;
    }

//    public static void main2(String[] args) {
//        List<List<String>> l = new ArrayList<>();
//        for (int i = 0; i < 11; i++) {
//            l.add(new ArrayList<>());
//        }
//        for (int i = 0; i < 1024; i++) {
//            String b = Integer.toBinaryString(i);
//            int counts = count1s(b);
//            l.get(counts).add(b);
//        }
//        double p = 0;
//
//        for (int i = 0; i < 11; i++) {
//            int counts = 0;
//            int size = l.get(i).size();
//            for (String s : l.get(i)) {
//                if (has3consecutive(s)) {
//                    counts++;
//                }
//            }
//            p += counts * Math.pow(1, i) * Math.pow(0, 10 - i);
//            System.out.printf("Number of 1s: %d and size: %d, number of 3 consecutive E = %d\n", i, size, counts);
//        }
//        System.out.println("P = " + p);
//    }

    public static void main(String[] args) {
        System.out.println(expectedGain());
    }
}
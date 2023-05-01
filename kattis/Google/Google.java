//import java.util.*;
//
//class Google {
//
//
//
//    static int[] rec(int[] arr) {
//        Set<Integer> s = new HashSet<Integer>();
//        for (int i = 0; i < arr.length; i++) {
//            s.add(arr[i]);
//        }
//        boolean ch = true;
//        while (ch) {
//            boolean check = false;
//            Integer[] er = s.toArray(new Integer[0]);
//            for (int i = 0; i < s.size(); i++) {
//                for (int j = i + 1; j < s.size(); j++) {
//                    int m = Math.abs(er[i] - er[j]);
//                    if (!s.contains(m)) {
//                        check = true;
//                        s.add(m);
//                    }
//                }
//            }
//            ch = check;
//        }
//        int[] res = new int[s.size()];
//        int q = 0;
//        for (int x : s) {
//            res[q] = x;
//            q ++;
//        }
//        return res;
//    }
//
//    static int q2(int N, int K, int[] arr) {
//        int[] ne = rec(arr);
//        if (K >= ne.length) {
//            return -1;
////        } else {
////            return quickSelect(N, 0, ne.length - 1, K);
//        }
//    }
//
//    static int solve(int N, int K, int[] arr) {
//        int[][] v = new int[N][N];
//        int largest = 0;
//        for (int i = 0; i < N; i++) {
//            int count = 0;
//            for (int j = 0; j < N; j++) {
//                if (i == j) {
//                    v[i][j] = -1;
//                } else {
//                    v[i][j] = Math.abs(arr[i] - arr[j]) % K;
//                    if (v[i][j] == 0) {
//                        count++;
//                    }
//                }
//            }
//            if (count > largest) {
//                largest = count;
//            }
//        }
//        return largest + 1;
//    }
//
//    public static void main(String[] args) {
//        int i = solve(6, 4, new int[]{10, 24, 12, 16, 20, 32});
//        System.out.println(i);
//    }
//}
import java.util.*;

class Solution {
    public static HashMap<String, Integer> m = new HashMap<>();
    public int numDecodings(String s) {
        int len = s.length();
        if (len == 0 || s.charAt(0) == '0') return 0;
        if (len == 1) return 1;
        if (m.containsKey(s)) {
            return m.get(s);
        }
        String x = s.substring(0, 1);
        String y = s.substring(0, 2);
        String x2 = s.substring(1);
        String y2 = s.substring(2);
        if (len == 2) {
            int y3 = Integer.parseInt(y);
            if (y3 <= 26) {
                if (y3 == 10 || y3 == 20) return 1;
                else return 2;
            }
            else return numDecodings(x2);
        }
        if (Integer.parseInt(y) <= 26) {
            m.put(s, numDecodings(x2) + numDecodings(y2));
        } else {
            m.put(s, numDecodings(x2));
        }
        return m.get(s);
    }
}
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        } else {
            int len = s.length();
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < numRows; i++) {
                int diff = 2*numRows - 2;
                for (int j = i; j < len; j+= diff) {
                    res.append(s.charAt(j));
                    int nextDiff = diff - 2*i;
                    if (i > 0 && i < numRows - 1 && (j + nextDiff) < len) {
                        res.append(s.charAt(j + nextDiff));
                    }
                }
            }
            return res.toString();
            // numRows - 1 + numRows - 1 = next
            // 0     6     2 
            // 1   5 7   1 3 
            // 2 4   8 0   4
            // 3     9     5
        }
    }
}
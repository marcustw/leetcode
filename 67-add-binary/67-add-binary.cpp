class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        string res = "";
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 0) {
                    res = "0" + res;
                } else {
                    res = "1" + res;
                }
                carry = 1;
            } else if (a[i] == '1' || b[j] == '1') {
                if (carry == 0) {
                    res = "1" + res;
                } else {
                    res = "0" + res;
                    carry = 1;
                }
            } else {
                if (carry == 0) {
                    res = "0" + res;
                } else {
                    res = "1" + res;
                    carry = 0;
                }
            }
            i--;
            j--;
        }
        while (i >= 0) {
            if (carry == 0) {
                res = a[i] + res;
            } else {
                if (a[i] == '1') {
                    res = "0" + res;
                } else {
                    res = "1" + res;
                    carry = 0;
                }
            }
            i--;
        }
        while (j >= 0) {
            if (carry == 0) {
                res = b[j] + res;
            } else {
                if (b[j] == '1') {
                    res = "0" + res;
                } else {
                    res = "1" + res;
                    carry = 0;
                }
            }
            j--;
        }
        if (carry == 1) res = "1" + res;
        return res;
    }
};
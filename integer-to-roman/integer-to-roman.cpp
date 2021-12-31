class Solution {
public:
    string intToRoman(int num) {
        map<int,string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";
        string res = "";
        int pow = 1000;
        while (num > 0 && pow > 0) {
            int di = num / pow;
            for (int i = 0; i < di;i++) {
                if (di == 9) {
                    res += m[pow] + m[pow * 10];
                    break;
                } else if (di == 4) {
                    res += m[pow] + m[pow * 5];
                    break;
                } else if (di ==  5) {
                    res += m[pow * 5];
                    break;
                } else if (di > 5) {
                    res += m[pow * 5];
                    for (int j = 0; j < di - 5; j++) {
                        res += m[pow];
                    }
                    break;
                } else {
                    res += m[pow];
                }
            }
            num = num % pow;
            pow = pow / 10;
        }
        return res;
    }
};
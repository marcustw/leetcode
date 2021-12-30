class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        string res = "";
        string x = strs[0];

        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < x.length()) {
                x = strs[i];
            }
        }
        for (int i = 0; i < x.length(); i++) {
            bool y = true;
            for (int j = 0; j < strs.size(); j++) {
                if (x[i] != strs[j][i]) {
                    y = false;
                    break;
                }
            }
            if (y) {
                res += x[i];
            } else {
                break;
            }
        }
        return res;
    }
};
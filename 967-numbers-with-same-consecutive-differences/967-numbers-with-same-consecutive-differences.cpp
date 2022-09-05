class Solution {
    vector<int> ans;
    
    void recurse(int n, int k, int len, int value, int prevDigit) {
        if (len == n) {
            ans.push_back(value);
            return;
        }
        value *= 10;
        int plus = prevDigit + k;
        int minus = prevDigit - k;
        if (plus <= 9) {
            recurse(n, k, len+1, value+plus, plus);
        }
        if (k != 0 && minus >= 0) {
            recurse(n, k, len+1, value+minus, minus);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i=1; i<=9; i++) {
            recurse(n, k, 1, i, i);
        }
        return ans;
    }
};
class Solution {
public:
    void backtrack(int open, int close, string s, vector<string>& res) {
        if (close < open || close < 0 || open < 0) return;
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        backtrack(open-1, close, s+'(', res);
        backtrack(open, close-1, s+')', res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, n, "", res);
        return res;
    }
};
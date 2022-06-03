class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        set<char> left={'(','{', '['};
        for (int i=0; i<s.length(); i++) {
            if (left.count(s[i])==1) {
                stk.push(s[i]);
            } else if (stk.empty()) {
                return false;
            } else if (s[i]==')') {
                if (stk.top()!='(') return false;
                stk.pop();
            } else if (s[i]==']') {
                if (stk.top()!='[') return false;
                stk.pop();
            } else {
                if (stk.top()!='{') return false;
                stk.pop();
            }
        }
        return stk.size()==0;
    }
};
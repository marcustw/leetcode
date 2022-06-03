class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c:s) {
            if (c=='(' || c=='[' || c=='{') stk.push(c);
            else {
                if (stk.empty()) return false;
                char k=stk.top();
                if (
                    (c==')' && k!='(') ||
                    (c=='}' && k!='{') ||
                    (c==']' && k!='[')
                ) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
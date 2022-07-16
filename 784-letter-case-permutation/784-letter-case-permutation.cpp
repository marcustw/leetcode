class Solution {
    vector<string> ans;
    
    void recurse(string s, string acc) {
        if (acc.length()==s.length()) {
            ans.push_back(acc);
            return;
        }
        int index=acc.length();
        if (isdigit(s[index])) {
            recurse(s,acc+s[index]);
        } else {
            recurse(s,acc+(char)tolower(s[index]));
            recurse(s,acc+(char)toupper(s[index]));
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        recurse(s,"");
        return ans;
    }
};
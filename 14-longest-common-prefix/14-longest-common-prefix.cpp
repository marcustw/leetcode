class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==1) return strs[0];
        string ans="";
        int l=0;
        char c;
        while (ans.length()<200) {
            string q=strs[0];
            if (q.length()==0 || l>=q.length()) return ans;
            c=q[l];
            for (int i=1; i<strs.size(); i++) {
                string s=strs[i];
                if (l>=s.length() || s[l]!=c) return ans;
            }
            ans+=c;
            l++;
        }
        return ans;
    }
};
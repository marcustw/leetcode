class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        int next=0;
        string ans="";
        while (next<s.length()) {
            if (next==s.length()-1 || s[next+1]==' ') {
                int q=next;
                while (q>=start) ans+=s[q--];
                start=next+1;
            }
            if (s[start]==' ') {
                ans+=" ";
                start++;
                next++;
            }
            next++;
        }
        return ans;
    }
};
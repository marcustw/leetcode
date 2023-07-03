class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length()!=goal.length()) return false;
        char a, b;
        int i, count=0, same=0;
        unordered_set<char> sed;
        for (int q=0; q<s.length(); ++q) {
            if (s[q]!=goal[q]) {
                if (count==2) return false;
                if (count==0) {
                    a=s[q], b=goal[q];
                    i=q;
                } else if (a!=goal[q] || b!=s[q]) return false;
                count++;
            } else {
                if (sed.find(s[q])!=sed.end()) same+=1;
                sed.insert(s[q]);
            }
        }
        return count==2 || (same && count%2==0);
    }
};
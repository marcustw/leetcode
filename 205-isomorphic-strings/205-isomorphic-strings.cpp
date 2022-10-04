class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        for (int i=0; i<s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
            } else if (m[s[i]] != t[i]) {
                return false;
            }
        }
        m.clear();
        for (int i=0; i<s.length(); i++) {
            if (m.find(t[i]) == m.end()) {
                m[t[i]] = s[i];
            } else if (m[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};
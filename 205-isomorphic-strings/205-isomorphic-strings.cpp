class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> m2;
        for (int i=0; i<s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
            } else if (m[s[i]] != t[i]) {
                return false;
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            } else if (m2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_set<char> sed(s.begin(), s.end());
        vector<int> m(26,0), m2(26,0);
        for (int i=0; i<s.length(); i++) {
            m[s[i]-'a']++;
            m2[t[i]-'a']++;
        }
        for (auto& c : sed) {
            if (m[c-'a'] != m2[c-'a']) return false;
        }
        return true;
    }
};
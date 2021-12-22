class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        } else {
            set<char> sed;
            int j = 0;
            int i = 0;
            int len = 0;
            int maxLen = 0;
            while (i < s.size()) {
                if (sed.count(s[i]) == 0) {
                    sed.insert(s[i]);
                    len++;
                    i++;
                } else {
                    sed.erase(s[j]);
                    j++;
                    len--;
                }
                maxLen = max(len, maxLen);
            }
            return maxLen;
        }
    }
};
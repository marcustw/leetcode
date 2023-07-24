class Solution {
public:
    string greatestLetter(string s) {
        int cnt[52]={};
        for (auto& c : s) {
            ++cnt[isupper(c) ? c-'A' : c-'a' + 26];
        }
        for (char c='Z'; c>='A'; --c)
            if (cnt[c-'A'] && cnt[c-'A'+26]) return string(1, c);

        return "";
    }
};
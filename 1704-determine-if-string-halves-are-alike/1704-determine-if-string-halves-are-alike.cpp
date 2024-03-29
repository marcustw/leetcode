class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
public:
    bool halvesAreAlike(string s) {
        int half = s.length() / 2;
        int ab[2] = {0, 0};
        for (int i=0; i<s.length(); i++) {
            if (vowels.find(tolower(s[i])) != vowels.end()) ab[i/half]++;
        }
        return ab[0] == ab[1];
    }
};
class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.length() / 2;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int a=0, b=0;
        for (int i=0; i<half; i++) {
            if (vowels.find(s[i]) != vowels.end()) a++;
        }
        for (int j=half; j<s.length(); j++) {
            if (vowels.find(s[j]) != vowels.end()) b++;
        }
        return a==b;
    }
};
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int lo=0, hi=s.length()-1;
        while (lo<hi) {
            while (lo<hi && vowels.find(s[lo]) == vowels.end()) lo++;
            while (lo<hi && vowels.find(s[hi]) == vowels.end()) hi--;
            swap(s[lo++], s[hi--]);
        }
        return s;
    }
};
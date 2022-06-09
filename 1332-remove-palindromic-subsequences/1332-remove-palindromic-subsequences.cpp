class Solution {
private:
    int isPalindrome(string& s) {
        int n=s.size();
        for (int i=0; i<n/2; i++) {
            if (s[i]!=s[n-i-1]) return 1;
        }
        return 0;
    }
public:
    int removePalindromeSub(string s) {
        return 1+isPalindrome(s);
    }
};
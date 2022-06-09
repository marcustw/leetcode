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
    /*
        - Idea is in a single step, you can remove a palindromic subsequence
        - if s is empty, do not need to remove
            - However, constraints given s.length() >= 1 so s will never be empty
        - If s is palindrome, just remove it
        - If s is not palindrome, remove all 'a' as palindromic subsequence, then remove all 'b'
    */
    int removePalindromeSub(string s) {
        return 1+isPalindrome(s);
    }
};
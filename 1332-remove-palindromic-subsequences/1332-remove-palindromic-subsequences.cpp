class Solution {
public:
    /*
        - Idea is in a single step, you can remove a palindromic subsequence
        - if s is empty, do not need to remove
            - However, constraints given s.length() >= 1 so s will never be empty
        - If s is palindrome, just remove it
        - If s is not palindrome, remove all 'a' as palindromic subsequence, then remove all 'b'
    */
    int removePalindromeSub(string s) {
        int n=s.size();
        for (int i=0; i<n/2; i++) {
            if (s[i]!=s[n-i-1]) return 2;
        }
        return 1;
    }
};
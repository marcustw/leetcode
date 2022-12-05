class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n==1) return "";
        int replaced=-1;
        char replacedChar;
        bool nonA=false;
        for (int i=0; i<n/2; i++) {
            if (palindrome[i] != 'a' && replaced==-1) {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};
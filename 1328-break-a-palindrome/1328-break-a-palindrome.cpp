class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n==1) return "";
        int replaced=-1;
        char replacedChar;
        bool nonA=false;
        for (int i=0; i<n; i++) {
            if (palindrome[i] != 'a' && replaced==-1) {
                replacedChar = palindrome[i];
                palindrome[i] = 'a';
                replaced = i;
            }
            if (palindrome[i] != 'a') {
                nonA=true;
            }
            if (i == n-1 && replaced==-1) {
                palindrome[i] = 'b';
            }
        }
        if (!nonA && replaced!=-1) {
            palindrome[replaced]=replacedChar;
            palindrome[n-1]='b';
        }
        
        return palindrome;
    }
};
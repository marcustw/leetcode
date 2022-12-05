class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n==1) return "";
        int replaced;
        char replacedChar;
        for (int i=0; i<n; i++) {
            if (palindrome[i] != 'a') {
                replacedChar = palindrome[i];
                palindrome[i] = 'a';
                replaced = i;
                break;
            }
            if (i == n-1) {
                palindrome[i] = 'b';
            }
        }
        
        // handle if palindrome is all 'a'
        unordered_set<char> s(palindrome.begin(), palindrome.end());
        if (s.size() == 1) {
            palindrome[replaced]=replacedChar;
            palindrome[n-1]='b';
        }
        
        return palindrome;
    }
};
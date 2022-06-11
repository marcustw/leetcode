class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int hi=n-1;
        int lo=0;
        while (lo<hi) {
            if (!isalnum(s[lo])) { 
                lo++;
                continue;
            }
            if (!isalnum(s[hi])) {
                hi--;
                continue;
            }
            if (tolower(s[lo])!=tolower(s[hi])) return false;
            lo++;
            hi--;
        }
        return true;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if (n<=1) return s;
        int index=0;
        int len=1;
        
        for (int i=0; i<n; i++) {
            int r=i;
            while (r<n && s[i]==s[r]) {
                r++;
            }
            int l=i-1;
            while (l>=0 && r<n && s[l]==s[r]) {
                l--;
                r++;
            }
            int len2=r-l-1;
            if (len2>len) {
                len=len2;
                index=l+1;
            }
        }
        
        return s.substr(index,len);
    }
};
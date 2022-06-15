class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        if (n==0) return 0;
        int m=haystack.length();
        int i=0;
        while (i+n<=m) {
            if (haystack.substr(i,n)==needle) return i;
            else i++;
            
            while (i+n<=m && haystack[i]!=needle[0]) i++;
        }
        return -1;
    }
};
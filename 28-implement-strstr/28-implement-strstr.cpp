class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        if (n==0 || haystack==needle) return 0;
        int i=0;
        while (i+n<=haystack.length()) {
            if (haystack[i]!=needle[0]) {
                i++;
                continue;
            }
            bool found=true;
            for (int j=0; j<n; j++) {
                if (needle[j]!=haystack[i+j]) {
                    found=false;
                    break;
                }
            }
            if (found) return i;
            else i++;
        }
        
        return -1;
    }
};
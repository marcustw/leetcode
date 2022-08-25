class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<0) return false;
        // 100 & 011 -> 0 (bin/dec)
        // 110 & 101 -> 100 (bin) -> 4 (dec)
        // if n is power of 2, it always give 0 when logical and with n-1
        return n && (n&(n-1)) == 0;
    }
};
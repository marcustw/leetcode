class Solution {
    long hash(int n) {
        long res = 0;
        for (int N=n; N>0; N/=10) {
            res += pow(10, N%10);
        }
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
        long digits = hash(n);
        for (int i=0; i<32; i++) {
            if (hash(1 << i) == digits) {
                return true;
            }
        }
        return false;
    }
};
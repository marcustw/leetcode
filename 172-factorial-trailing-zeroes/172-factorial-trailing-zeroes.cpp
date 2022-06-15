class Solution {
public:
    int trailingZeroes(int n) {
        if (n<=4) return 0;
        int ans=0, i=1;
        for (long i=5; n/i>0; i*=5) {
            ans+=n/i;
        }
        return ans;
    }
};
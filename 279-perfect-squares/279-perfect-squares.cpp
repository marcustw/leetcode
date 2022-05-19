class Solution {
public:
    int memo[10001] = {};
    int recurse(int n) {
        if (n == 0) return 0;
        if (memo[n] > 0) return memo[n];
        int res = INT_MAX;
        for(int i=1; i<=sqrt(n); i++) {
            res = min(res, 1+recurse(n-(i*i)));
        }
        memo[n] = res;
        return res;
    }
    
    int numSquares(int n) {
        return recurse(n);
    }
};
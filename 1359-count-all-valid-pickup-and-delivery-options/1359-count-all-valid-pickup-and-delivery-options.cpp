class Solution {
    long MOD=1000000007;

    //(2n)! / (2*2*2...*2) = (2n)! / (2^n)
    int recurse(int n, long res) {
        if (n==0) return res;
        return recurse(n-1, res * (2*n - 1) * n % MOD);
    }
public:
    int countOrders(int n) {
        if (n==1) return 1;
        return recurse(n, 1);
    }
};
class Solution {
public:
    double recurse(double x, long long n, map<int, double>& mep) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        if (mep.count(n)) {
            return mep[n];
        }
        if (n % 2 == 0) {
            mep[n] = recurse(x, n/2, mep) * recurse(x, n/2, mep);
        } else {
            mep[n] = x * recurse(x, n-1, mep);
        }
        return mep[n];
    }
    
    double myPow(double x, int n) {
        double y = 1.0;
        if (x == y) return 1;
        if (n == 0) return 1;
        if (n == 1) return x;
        map<int, double> mem;
        if (n < 0) return recurse(1/x, - (long long) n, mem);
        else return recurse(x, n, mem);
    }
};
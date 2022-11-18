class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=6) return n;
        vector<int> m(n, 1);
        int t=0, t2=0, t3=0;
        for (int i=1; i<n; i++) {
            int a = m[t]*2;
            int b = m[t2]*3;
            int c = m[t3]*5;
            m[i] = min(a, min(b,c));
            if (m[i] == a) t++;
            if (m[i] == b) t2++;
            if (m[i] == c) t3++;
        }
        return m[n-1];
    }
};
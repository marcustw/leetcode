class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> nones(n,false);
        int ans=1;
        int upper=(int)sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (nones[i]) continue;
            ans++;
            if (i>upper) continue;
            for (int j=i*i; j<n; j+=2*i) {
                nones[j]=true;
            }
        }
        return ans;
    }
};
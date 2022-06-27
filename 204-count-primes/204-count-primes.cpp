class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<int> nones(n+1,0);
        int ans=1;
        for (int i=3; i<n; i+=2) {
            if (nones[i]==0) {
                ans++;
                for (int j=2; j*i<n; j++) {
                    nones[j*i]=1;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> nones(n,false);
        int ans=1;
        for (int i=3; i<n; i+=2) {
            if (!nones[i]) {
                ans++;
                for (int j=2; j*i<n; j++) {
                    nones[j*i]=true;
                }
            }
        }
        return ans;
    }
};
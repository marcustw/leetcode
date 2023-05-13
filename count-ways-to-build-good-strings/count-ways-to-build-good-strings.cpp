class Solution {
    int MOD=1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp{1};
        int total=0;
        for (int i=1; i<high+1; i++) {
            dp.push_back(0);
            if (i>=zero) dp[i]+=dp[i-zero];
            if (i>=one) dp[i]+=dp[i-one];
            dp[i]%=MOD;
            if (i>=low && i<=high) {
                total+=dp[i];
                total%=MOD;
            }
        }
        return total;
    }
};
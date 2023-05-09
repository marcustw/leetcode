class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<=1) return n;
        vector<int> dp(n+1, 0);
        dp[1]=1;
        int ans=1;
        for (int i=2; i<=n; i++) {
            if (i%2==0) dp[i]=dp[i/2];
            else dp[i]=dp[i/2]+dp[i/2+1];
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
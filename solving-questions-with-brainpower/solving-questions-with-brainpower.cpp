class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        long long ans=0L, dp[200001];
        memset(dp, 0L, sizeof(dp));
        dp[n-1]=questions[n-1][0];
        for (int i=n-2; i>=0; i--) {
            dp[i]=max(dp[i+1], questions[i][0] + dp[questions[i][1]+i+1]);
        }
        return dp[0];
    }
};
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size(), ans[n+1][10001];
        bool dp[n+1][10001];
        memset(ans, 0, sizeof(ans));
        memset(dp, 0, sizeof(dp));
        dp[0][5000]=true;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=10000; ++j) {
                if (j-rods[i] >= 0 && dp[i][j-rods[i]]) {
                    dp[i+1][j] = true;
                    ans[i+1][j] = max(ans[i+1][j], ans[i][j-rods[i]] + rods[i]);
                }
                if (j+rods[i] <= 10000 && dp[i][j+rods[i]]) {
                    dp[i+1][j] = true;
                    ans[i+1][j] = max(ans[i+1][j], ans[i][j+rods[i]]);
                }
                if (dp[i][j]) {
                    dp[i+1][j] = true;
                    ans[i+1][j] = max(ans[i+1][j], ans[i][j]);
                }
            }
        }
        return ans[n][5000];
    }
};
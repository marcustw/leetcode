class Solution {
    int MOD=1e9+7;
    int ans=0LL;
    int dp[1001][1001];

    int dfs(vector<vector<int>>& g, int i, int j, int v) {
        if (i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]<=v) return 0;
        if (!dp[i][j]) {
            v=g[i][j];
            dp[i][j]= (1LL + dfs(g, i+1, j, v)
                           + dfs(g, i-1, j, v)
                           + dfs(g, i, j-1, v)
                           + dfs(g, i, j+1, v)) % MOD;
        }
        return dp[i][j];
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                ans = (ans + dfs(grid, i, j, 0)) % MOD;
            }
        }
        return ans;
    }
};
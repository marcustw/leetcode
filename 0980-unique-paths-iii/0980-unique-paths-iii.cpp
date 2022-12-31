class Solution {
    int ans=0;

    void recurse(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int m, int n, int numSquares, int k) {
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1 || dp[i][j]==-1) return;
        if (grid[i][j]==2) {
            if (numSquares == k) ans++;
            return;
        }
        dp[i][j] = -1;
        numSquares++;
        recurse(grid, i+1, j, dp, m, n, numSquares, k);
        recurse(grid, i-1, j, dp, m, n, numSquares, k);
        recurse(grid, i, j+1, dp, m, n, numSquares, k);
        recurse(grid, i, j-1, dp, m, n, numSquares, k);
        dp[i][j] = 0;
    }


public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        int numSquares=0, m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j]==0) numSquares++;
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        recurse(grid, startX, startY, dp, m, n, -1, numSquares);
        return ans;
    }
};
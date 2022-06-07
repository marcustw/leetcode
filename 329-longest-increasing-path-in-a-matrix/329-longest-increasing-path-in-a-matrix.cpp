class Solution {
private:
    vector<vector<int>> steps{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> dp;
    
    int recurse(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if (dp[i][j]!=0) return dp[i][j];
        int ans=1;
        for (int dir=0; dir<4; dir++) {
            int ni=i+steps[dir][0];
            int nj=j+steps[dir][1];
            if (ni<0 || nj<0 || ni >= m || nj >= n || matrix[ni][nj] <= matrix[i][j]) continue;
            ans=max(ans,1+recurse(matrix,ni,nj,m,n));
        }
        dp[i][j]=ans;
        return ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=1;
        int m=matrix.size(); int n=matrix[0].size();
        dp.resize(m,vector<int>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans=max(ans,recurse(matrix,i,j,m,n));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<long> dp(m+1,0);
        dp[m-1]=1;
        for (int j=n-1; j>=0; j--) {
            for (int i=m-1; i>=0; i--) {
                if (obstacleGrid[i][j]==1) dp[i]=0;
                else dp[i]+=dp[i+1];
            }
        }
        return (int) dp[0];
    }
};
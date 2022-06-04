class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (i==0 || j==0) dp[i][j]=0;
                else if (text1[i-1]==text2[j-1]) {
                    dp[i][j]=dp[i-1][j-1] + 1;
                } else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
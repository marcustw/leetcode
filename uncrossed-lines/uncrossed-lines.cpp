class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(), dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n1; i++) {
            for (int j=1; j<=n2; j++) {
                dp[i][j] = nums1[i-1] == nums2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);  
            }
        }
        return dp[n1][n2];
    }
};

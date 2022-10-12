class Solution {

public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cs(n, 1);
        int lis=1;
        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] == dp[j]+1) {
                        cs[i]+=cs[j];
                    } else if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        cs[i] = cs[j];
                    }
                }
            }
            if (lis==dp[i]) {
                ans+=cs[i];
            } else if (lis < dp[i]) {
                ans = cs[i];
                lis = dp[i];
            }
        }
        
        return ans;
    }
};
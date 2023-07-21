class Solution {

public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), lis=1, ans=0;
        vector<int> dp(n,1), cs(n,1);
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
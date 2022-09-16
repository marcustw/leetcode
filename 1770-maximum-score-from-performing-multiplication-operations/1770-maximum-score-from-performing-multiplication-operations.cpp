class Solution {
    vector<vector<int>> dp = vector<vector<int>>(1000, vector<int>(1000, INT_MIN));
    
    int maxScore(vector<int>& nums, vector<int>& ms, int i, int k) {
        if (k == ms.size()) return 0;
        if (dp[i][k] != INT_MIN) return dp[i][k];
        int left = maxScore(nums, ms, i+1, k+1) + nums[i] * ms[k];
        int right = maxScore(nums, ms, i, k+1) + nums[nums.size() - (k-i) - 1] * ms[k];
        dp[i][k] = max(left, right);
        return dp[i][k];
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int ans = 0;
        int i=0, k=0;
        return maxScore(nums, multipliers, i, k);
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long,int>> dp(n);
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                long diff = (long) nums[i] - nums[j];
                int count;
                if (dp[j].find(diff) != dp[j].end()) {
                    int count = dp[j][diff];
                    dp[i][diff] += (count+1);
                    ans += count;
                } else {
                    dp[i][diff] += 1;
                }
            }
        }
        return ans;
    }
};
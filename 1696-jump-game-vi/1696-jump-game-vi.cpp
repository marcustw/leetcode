class Solution {
    int ans=0;
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0]=nums[0];
        deque<int> q{0};
        for (int i=1; i<n; i++) {
            if (q.front()<i-k) q.pop_front();
            dp[i]=nums[i]+dp[q.front()];
            while (!q.empty() && dp[q.back()]<=dp[i]) q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};
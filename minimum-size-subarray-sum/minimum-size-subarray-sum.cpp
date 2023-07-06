class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // O(n logn) solution
        int n=nums.size(), ans=n+1;
        vector<int> sums(n+1, 0);
        for (int i=1; i<=n; ++i) sums[i] = sums[i-1] + nums[i-1];
        for (int i=n; i>=0 && sums[i]>=target; --i) {
            int j=upper_bound(sums.begin(), sums.end(), sums[i]-target) - sums.begin();
            ans=min(ans, i-j+1);
        }
        return ans==n+1 ? 0 : ans;
    }
};
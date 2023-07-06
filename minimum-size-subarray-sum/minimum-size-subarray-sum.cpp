class Solution {
    int solve(int target, vector<int>& nums) {
        // O(n) solution
        int n=nums.size(), sum=0, ans=n+1, lo=0;
        for (int i=0; i<n; ++i) {
            while (sum+nums[i]-nums[lo]>=target && lo<i) {
                sum-=nums[lo++];
            }
            sum+=nums[i];
            if (sum>=target) ans=min(i-lo+1, ans);
        }
        return ans==n+1 ? 0 : ans;
    }

    int solve2(int target, vector<int>& nums) {
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

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        return solve(target, nums);
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
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
};
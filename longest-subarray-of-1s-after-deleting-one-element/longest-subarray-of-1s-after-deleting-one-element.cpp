class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lo=0, hi=0, ans=0, count=0;
        while (hi<nums.size()) {
            if (nums[hi++]==0) count++;
            if (count<=1) {
                ans=max(ans, hi-lo-1);
            } else {
                while (count>1) {
                    count-=(nums[lo++]==0);
                }
            }
        }
        return ans;
    }
};
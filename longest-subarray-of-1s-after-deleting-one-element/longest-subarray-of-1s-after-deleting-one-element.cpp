class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lo=0, hi, k=1;
        for (hi=0; hi<nums.size(); ++hi) {
            if (nums[hi]==0) k--;
            if (k<0 && nums[lo++]==0) k++;
        }
        return hi-lo-1;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo=0, hi;
        for (hi=0; hi<nums.size(); ++hi) {
            if (nums[hi]==0) k--;
            if (k<0 && nums[lo++]==0) k++;
        }
        return hi-lo;
    }
};
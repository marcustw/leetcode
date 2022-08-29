class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while (lo <= hi) {
            int m = lo + (hi-lo)/2;
            if (nums[m] == target) return true;
            if (nums[lo] == nums[m] && nums[hi] == nums[m]) {
                lo++;
                hi--;
            } else if (nums[lo] <= nums[m]) {
                if (nums[lo] <= target && nums[m] > target) {
                    hi = m-1;
                } else {
                    lo = m+1;
                }
            } else {
                if (nums[m] < target && nums[hi] >= target) {
                    lo = m+1;
                } else {
                    hi = m-1;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        if (nums.size()==2) return nums[0]>nums[1] ? 0 : 1;
        while (lo<hi) {
            int mid=(lo+hi)/2;
            if (mid==0 || mid==nums.size()-1) return mid;
            if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if (nums[mid] < nums[mid+1]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
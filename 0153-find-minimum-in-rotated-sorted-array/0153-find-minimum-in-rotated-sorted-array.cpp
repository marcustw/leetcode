class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int lo=0, hi=nums.size()-1;
        while (lo<hi) {
            int m=lo+(hi-lo)/2;
            if (m!=0 && nums[m]<nums[m-1]) return nums[m];
            if (nums[m]>nums[hi]) {
                lo=m+1;
            } else {
                hi=m-1;
            }
        }
        return nums[lo];
    }
};
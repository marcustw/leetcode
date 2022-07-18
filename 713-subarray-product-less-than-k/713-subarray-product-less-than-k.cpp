class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1, l=0, ans=0;
        for (int r=0; r<nums.size(); r++) {
            prod*=nums[r];
            while (prod>=k && l<=r) prod/=nums[l++];
            ans+=(r-l)+1;
        }
        return ans;
    }
};
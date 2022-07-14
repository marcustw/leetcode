class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lo=0;
        int n=nums.size();
        int hi=n-1;
        int i=n-1;
        vector<int> ans(n);
        while (i>=0) {
            if (abs(nums[lo]) > abs(nums[hi])) {
                ans[i]=pow(nums[lo],2);
                lo++;
            } else {
                ans[i]=pow(nums[hi],2);
                hi--;
            }
            i--;
        }
        return ans;
    }
};
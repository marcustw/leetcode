class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], sum=0;;
        for (int& num : nums) {
            if (sum<0) {
                sum=num;
            } else {
                sum+=num;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};
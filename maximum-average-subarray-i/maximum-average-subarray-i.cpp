class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN, total=0;
        int lo=0, hi, cur=k;
        for (hi=0; hi<nums.size(); ++hi) {
            if (cur>0) {
                total+=nums[hi];
                cur--;
            }
            if (cur==0) {
                ans=max(ans, total);
                total-=nums[lo++];
                cur++;
            }
        }
        return ans/k;
    }
};
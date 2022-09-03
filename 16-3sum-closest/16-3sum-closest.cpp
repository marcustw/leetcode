class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int lo=i+1;
            int hi=nums.size()-1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return target;
                if (abs(target-sum) < abs(target-ans)) {
                    ans = sum;
                }
                if (sum>target) hi--;
                else lo++;
            }
        }
        return ans;
    }
};
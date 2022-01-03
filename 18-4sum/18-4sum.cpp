class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l = nums.size();
        for (int i = 0; i < l - 3; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int numsi = nums[i];
            for (int j = i + 1; j < l - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;
                int numsj = nums[j];
                int total1 = numsj + numsi;
                int lo = j + 1;
                int hi = l - 1;
                while (lo < hi) {
                    int total2 = nums[lo] + nums[hi];
                    if (target - total1 == total2) {
                        vector<int> lst;
                        lst.push_back(numsi);
                        lst.push_back(numsj);
                        lst.push_back(nums[lo]);
                        lst.push_back(nums[hi]);
                        res.push_back(lst);
                        lo++;
                        hi--;
                        while (lo < hi && nums[lo] == nums[lo-1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi+1]) hi--;
                    } else if (total2 < target - total1) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            } 
        }
        return res;
    }
};
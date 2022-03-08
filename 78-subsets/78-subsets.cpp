#include <algorithm>

class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, int index, vector<int> subset) {
        
        res.push_back(subset);
        
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(res, nums, i+1, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(res, nums, 0, subset);
        return res;
    }
};
class Solution {
    vector<vector<int>> ans;
    
    void recurse(vector<int>& nums, vector<int> v, int index) {
        ans.push_back(v);
        for (int i=index; i<nums.size(); i++) {
            v.push_back(nums[i]);
            recurse(nums,v,i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        recurse(nums,v,0);
        return ans;
    }
};
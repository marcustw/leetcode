class Solution {
    vector<vector<int>> ans;
    
    // backtracking
    void recurse(vector<int>& nums, vector<int>& v, int index) {
        ans.push_back(v);
        for (int i=index; i<nums.size(); i++) {
            if (i==index || nums[i] != nums[i-1]) {
                v.push_back(nums[i]);
                recurse(nums,v,i+1);
                v.pop_back();
            }
        }
    }
    
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n logn) where n<= 10 -> O(1)
        vector<int> v;
        recurse(nums,v,0);
        return ans;
    }
};
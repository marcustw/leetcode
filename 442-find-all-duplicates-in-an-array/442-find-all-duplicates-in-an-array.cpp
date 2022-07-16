class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> sed;
        vector<int> ans;
        for (auto& x : nums) {
            if (sed.count(x)) ans.push_back(x);
            else sed.insert(x);
        }
        return ans;
    }
};
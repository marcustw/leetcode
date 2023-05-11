class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;
        vector<int> ans;
        for (const auto& v : nums) {
            for (const int& i : v) m[i]++;
        }
        for (auto itr=m.begin(); itr!=m.end(); itr++) {
            if (itr->second == nums.size()) ans.push_back(itr->first); 
        }
        return ans;
    }
};
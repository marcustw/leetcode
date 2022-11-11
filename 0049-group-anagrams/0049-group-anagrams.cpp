class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        for (const string& s : strs) {
            string v  = s;
            std::sort(v.begin(), v.end());
            if (m.find(v) != m.end()) {
                ans[m[v]].push_back(s);
            } else {
                m[v] = ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};
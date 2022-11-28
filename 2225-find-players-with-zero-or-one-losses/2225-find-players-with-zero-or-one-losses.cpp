class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, int> losses;
        for (auto& match : matches) {
            losses[match[1]]++;
            if (losses.find(match[0]) == losses.end()) {
                losses[match[0]] = 0;
            }
        }
        for (auto& p : losses) {
            if (p.second <= 1) {
                ans[p.second].push_back(p.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
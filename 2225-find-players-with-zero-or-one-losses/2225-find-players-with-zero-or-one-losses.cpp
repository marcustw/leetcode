class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, int> losses;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& match : matches) {
            if (losses.find(match[1]) == losses.end()) {
                q.push(match[1]);
            }
            losses[match[1]]++;
            if (losses.find(match[0]) == losses.end()) {
                losses[match[0]] = 0;
                q.push(match[0]);
            }
        }
        while (!q.empty()) {
            int player = q.top();
            q.pop();
            if (losses[player] == 0) {
                ans[0].push_back(player);
            } else if (losses[player] == 1) {
                ans[1].push_back(player);
            }
        }
        return ans;
    }
};
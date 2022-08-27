class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==0) return {};
        if (n==1) return {0};
        vector<int> ans;
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> m;
        for (auto& e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
            degree[e[1]]++;
            degree[e[0]]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (degree[i]==1) q.push(i);
        }
        while (!q.empty()) {
            ans = {};
            int qSize = q.size();
            for (int i=0; i<qSize; i++) {
                int cur = q.front();
                q.pop();
                ans.push_back(cur);
                for (auto& v : m[cur]) {
                    degree[v]--;
                    if (degree[v]==1) q.push(v);
                }                
            }

        }
        return ans;
    }
};
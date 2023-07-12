class Solution {
    unordered_set<int> visited;
    unordered_set<int> cycles;
    unordered_set<int> safes;

    bool dfs(const vector<vector<int>>& graph, int u) {
        if (safes.find(u)!=safes.end()) return true;
        if (cycles.find(u)!=cycles.end()) return false;
        if (visited.find(u)!=visited.end()) {
            cycles.insert(u);
            return false;
        }
        visited.insert(u);
        for (const int& v : graph[u]) {
            if (!dfs(graph, v)) {
                cycles.insert(u);
                return false;
            }
        }
        safes.insert(u);
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        for (int i=0; i<graph.size(); ++i) {
            if (dfs(graph, i)) ans.push_back(i);
        }
        return ans;
    }
};
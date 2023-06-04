class Solution {
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && graph[i][j] && !visited[j]) {
                dfs(j, graph, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int n=isConnected.size();
        vector<bool> visited(n, false);
        int ans=0;
        for (int i=0; i<visited.size(); i++) {
            ans += !visited[i] ? dfs(i, isConnected, visited), 1 : 0;
        }
        return ans;
    }
};
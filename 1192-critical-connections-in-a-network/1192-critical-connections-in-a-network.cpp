// ref: https://www.youtube.com/watch?v=Rhxs4k6DyMM&ab_channel=TECHDOSE
class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
    vector<int> discoveryTime, lowTime;
    int time = 1;
    
    void dfs(int curr, int prev) {
        discoveryTime[curr] = time;
        lowTime[curr] = time;
        time++;
        for (int next : edgeMap[curr]) {
            if (discoveryTime[next] == 0) {
                dfs(next, curr);
                lowTime[curr] = min(lowTime[curr], lowTime[next]);
            } else if (next != prev) {
                lowTime[curr] = min(lowTime[curr], discoveryTime[next]);
            }
            if (discoveryTime[curr] < lowTime[next]) {
                ans.push_back({curr, next});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n <= 2) return connections;
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        discoveryTime = vector<int>(n);
        lowTime = vector<int>(n);
        dfs(0, -1);
        return ans;
    }
};
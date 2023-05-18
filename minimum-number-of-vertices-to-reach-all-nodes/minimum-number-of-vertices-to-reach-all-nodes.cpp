class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n, 0), ans;
        for (vector<int>& e : edges) {
            indegrees[e[1]]++;
        }
        for (int i=0; i<n; i++) {
            if (indegrees[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
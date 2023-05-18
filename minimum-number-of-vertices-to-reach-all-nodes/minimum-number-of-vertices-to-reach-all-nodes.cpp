class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0), ans;
        for (auto& e : edges) deg[e[1]]++;
        for (int i=0; i<n; i++)
            if (!deg[i]) ans.push_back(i);
        return ans;
    }
};
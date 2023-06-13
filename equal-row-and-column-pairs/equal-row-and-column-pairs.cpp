class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        map<vector<int>, int> m;

        for (auto& v : grid) m[v]++;

        for (int i=0; i<n; i++) {
            vector<int> v;
            for (int j=0; j<n; j++) v.push_back(grid[j][i]);
            ans+=m[v];
        }

        return ans;
    }
};
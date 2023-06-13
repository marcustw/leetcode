class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;

        unordered_map<string, int> m;

        for (int i=0; i<n; i++) {
            string s=to_string(grid[i][0]);
            for (int j=1; j<n; j++) {
                s+="-"+to_string(grid[i][j]);
            }
            m[s]++;
        }

        for (int i=0; i<n; i++) {
            string s=to_string(grid[0][i]);
            for (int j=1; j<n; j++) {
                s+="-"+to_string(grid[j][i]);
            }
            ans+=m[s];
        }

        return ans;
    }
};
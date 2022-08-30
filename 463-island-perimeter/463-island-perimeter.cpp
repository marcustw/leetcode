class Solution {
    int isIsland(vector<vector<int>>& grid, int i, int j, int m ,int n) {
        if (i<0 || j<0 || i==m || j==n) return 0;
        return grid[i][j]==1;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0, m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    sum+=4;
                    sum-= (isIsland(grid, i-1, j, m, n) +
                           isIsland(grid, i, j-1, m, n) +
                           isIsland(grid, i+1, j, m, n) +
                           isIsland(grid, i, j+1, m, n));
                }
            }
        }
        return sum;
    }
};
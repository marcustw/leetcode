class Solution {
    int count=0;
    int ans=0;
    void recurse(vector<vector<int>>& grid, int i, int j, int r, int c) {
        if (i<0 || j<0 || i>=r || j>=c || grid[i][j]==0) return;
        grid[i][j]=0;
        count++;
        recurse(grid,i+1,j,r,c);
        recurse(grid,i-1,j,r,c);
        recurse(grid,i,j+1,r,c);
        recurse(grid,i,j-1,r,c);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j]) {
                    count=0;
                    recurse(grid,i,j,r,c);
                    ans=max(count,ans);
                }
            }
        }
        return ans;
    }
};
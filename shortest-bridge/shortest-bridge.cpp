typedef pair<int,int> P;

class Solution {
    queue<P> q;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int n) {
        if (i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1) return;
        grid[i][j]=2;
        q.push({i, j});
        dfs(grid, i+1, j, n);
        dfs(grid, i-1, j, n);
        dfs(grid, i, j+1, n);
        dfs(grid, i, j-1, n);
    }

    int bfs(vector<vector<int>>& grid) {
        int d=0, ans=INT_MAX;
        while (!q.empty()) {
            int n=q.size();
            while (n-->0) {
                P p = q.front(); q.pop();
                for (int h=0; h<4; h++) {
                    int x=dir[h][0]+p.first;
                    int y=dir[h][1]+p.second;
                    if (x<0 || y<0 || x>=grid.size() || y>=grid.size()) {
                        continue;
                    } else if (grid[x][y]==1) {
                        ans=min(ans, d);
                    } else if (grid[x][y]==0) {
                        q.push({x, y});
                        grid[x][y]=2;
                    }
                }
            }
            d++;
        }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), found=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1 && found==0) {
                    dfs(grid, i, j, n);
                    q.push({i, j});
                    found = 1;
                    break;
                }
            }
            if (found==1) break;
        }
        return bfs(grid);
    }
};

/*
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1
*/
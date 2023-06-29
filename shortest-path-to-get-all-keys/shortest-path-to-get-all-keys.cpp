class Solution {
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int check(int bits, char c) {
        int ch=c-'A', cs=(1<<ch);
        return (cs & bits) == cs;
    }

public:
    // 111111 = all keys found = 63
    // 000000 = all keys not found
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(), m=grid[0].length(), ans=-1, numKeys=0, numLocks;
        vector<vector<unordered_set<int>>> visited(n, vector<unordered_set<int>>(m));
        queue<vector<int>> q;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j]=='@') {
                    q.push({i, j, 0});
                }
                if (islower(grid[i][j])) numKeys += (1<<(grid[i][j]-'a'));
                if (isupper(grid[i][j])) numLocks += (1<<(grid[i][j]-'A'));
            }
        }
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                vector<int> p=q.front();
                int x=p[0], y=p[1], z=p[2];
                q.pop();
                if (z==numKeys) return ans;
                if (visited[x][y].find(z)!=visited[x][y].end()) continue;
                visited[x][y].insert(z);
                if (islower(grid[x][y])) z|=(1<<(grid[x][y]-'a'));
                if (isupper(grid[x][y]) && !check(z, grid[x][y])) {
                    continue;
                }
                for (int j=0; j<4; ++j) {
                    int nx=x+dir[j][0], ny=y+dir[j][1];
                    if (nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]=='#') continue;
                    q.push({nx, ny, z});
                }
            }
            ++ans;
        }
        return -1;
    }
};
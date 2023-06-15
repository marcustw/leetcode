class Solution {
    int x, y, ans=INT_MAX;
    vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        x=entrance[0], y=entrance[1];
        q.push({x, y});
        int steps=1;
        maze[x][y]='+';
        while (!q.empty()) {
            int l=q.size();
            for (int i=0; i<l; ++i) {
                pair<int,int> p=q.front(); q.pop();
                for (int j=0; j<4; ++j) {
                    int nx=p.first+dir[j][0], ny=p.second+dir[j][1];
                    if (nx<0 || ny<0 || nx>=maze.size() || ny>=maze[0].size() || maze[nx][ny]=='+') continue;
                    if (nx==0 || ny==0 || nx==maze.size()-1 || ny==maze[0].size()-1) return steps;
                    maze[nx][ny]='+';
                    q.push({nx, ny});
                }
            }
            steps++;
        }
        return -1;
    }
};

/*
[["+",".","+","+","+","+","+"],
 ["+",".","+",".",".",".","+"],
 ["+",".","+",".","+",".","+"],
 ["+",".",".",".",".",".","+"],
 ["+","+","+","+",".","+","."]]
*/
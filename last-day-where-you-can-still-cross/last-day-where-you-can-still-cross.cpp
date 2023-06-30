class Solution {
    const int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<int> v;

    int find(int x) {
        if (v[x]<0) return x;
        return v[x]=find(v[x]);
    }

    void join(int x, int y) {
        int fx=find(x), fy=find(y);
        if (fx!=fy)
            v[fy]=fx;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        v=vector<int>(row*col+3, -1);
        int a=row*col+1, b=row*col+2;
        for (int i=0; i<col; ++i) {
            join(i, a);
            join((row-1)*col+i, b);
        }
        vector<vector<int>> grid(row, vector<int>(col, 1));
        for (int i=row*col-1; i>=0; --i) {
            int r=cells[i][0]-1, c=cells[i][1]-1;
            grid[r][c]=0;
            int key=r*col+c;
            for (int j=0; j<4; ++j) {
                int nr=r+dir[j][0], nc=c+dir[j][1];
                if (nr>=0 && nr<row && nc>=0 && nc<col && !grid[nr][nc]) {
                    int nkey=nr*col+nc;
                    join(key, nkey);
                }
                if (find(a)==find(b)) return i;
            }
        }

        return row*col-1;
    }
};
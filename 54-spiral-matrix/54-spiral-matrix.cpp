class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int layer=0;
        int dir=0; //0=right, 1=down, 2=left, 3=up
        int x=0;
        int y=0;
        int total=n*m;
        while (ans.size()<total) {
            while (y<m-layer) {
                ans.push_back(matrix[x][y++]);
            }
            if (ans.size()==total) break;
            y--;
            x++;
            while (x<n-layer) {
                ans.push_back(matrix[x++][y]);
            }
            if (ans.size()==total) break;
            x--;
            y--;
            while (y>=layer) {
                ans.push_back(matrix[x][y--]);
            }
            if (ans.size()==total) break;
            y++;
            x--;
            while (x>=layer+1) {
                ans.push_back(matrix[x--][y]);
            }
            layer++;
            x=layer;
            y=layer;
        }
        return ans;
    }
};

/*

[[1,2,3,4],
 [5,6,7,8],
 [9,10,11,12]]

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int dir=0, i=0, j=0, size=1, total=n*n, radius=0;
        while (size<=total) {
            if (dir==0) {  // move right
                while (j<n-radius) ans[i][j++] = size++;
                j=n-1-radius;
                i++;
            } else if (dir==1) {  // move down
                while (i<n-radius && size<=total) ans[i++][j] = size++;
                i=n-1-radius;
                j--;
            } else if (dir==2) {  // move left
                while (j>=radius) ans[i][j--] = size++;
                j=radius;
                i--;
                radius++;
            } else {  // move up
                while (i>=radius) ans[i--][j] = size++;
                j++;
                i=radius;
            }
            dir++;
            dir%=4;
        }
        return ans;
    }
};
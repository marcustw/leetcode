class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), t=n*m, i=0, j=0, r=0, d=0;
        vector<int> ans;
        while (ans.size()<t) {
            switch(d) {
                case 0: // going right
                    while (j<m-r) ans.push_back(matrix[i][j++]);
                    i++;
                    j=m-1-r;
                    d=1;
                    break;
                case 1: // going down
                    while (i<n-r) ans.push_back(matrix[i++][j]);
                    i=n-1-r;
                    j--;
                    d=2;
                    break;
                case 2: // going left
                    while (j>=r) ans.push_back(matrix[i][j--]);
                    j=r;
                    i--;
                    d=3;
                    r++;
                    break;
                case 3:
                    while (i>=r) ans.push_back(matrix[i--][j]);
                    i=r;
                    j++;
                    d=0;
                    break;
                default:
                    break;

            }
        }
        return ans;
    }
};

/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
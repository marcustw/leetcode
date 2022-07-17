class Solution {
    vector<vector<vector<int>>> dp;
    const int mod=1000000007;
    
    int recurse(int m, int n, int maxMove, int row, int col) {
        if (row<0 || row>=m || col<0 || col>=n) return 1;
        if (maxMove==0) return 0;
        if (dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];
        int moves = recurse(m,n,maxMove-1,row+1,col)%mod;
        moves=(moves+recurse(m,n,maxMove-1,row-1,col))%mod;
        moves=(moves+recurse(m,n,maxMove-1,row,col+1))%mod;
        moves=(moves+recurse(m,n,maxMove-1,row,col-1))%mod;
        dp[row][col][maxMove]=moves;
        return dp[row][col][maxMove];
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp=vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return recurse(m,n,maxMove,startRow,startColumn);
    }
};
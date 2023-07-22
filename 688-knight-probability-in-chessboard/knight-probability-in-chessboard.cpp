class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        if (row<0 || row>=n || col<0 || col>=n) return 0;
        if (dp.count(row) && dp[row].count(col) && dp[row][col].count(k))
            return dp[row][col][k];
        if (k==0) return 1.0;
        double total=0.0;
        for (auto& dir : directions)
            total+=knightProbability(n, k-1, row-dir[0], col-dir[1]);
        double ans=total/8;
        return dp[row][col][k]=ans;
    }
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    int directions[8][2] {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
};
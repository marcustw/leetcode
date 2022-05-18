class Solution {
public:
    void recurse(int i, int j, int m, int n, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i > m-1 || j > n-1 || board[i][j] != 'O') return;
        board[i][j] = 'Y';
        recurse(i+1,j  ,m,n,board);
        recurse(i-1,j  ,m,n,board);
        recurse(i  ,j-1,m,n,board);
        recurse(i  ,j+1,m,n,board);

    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') {
                recurse(i,0,m,n,board);
            }
            if (board[i][n-1] == 'O') {
                recurse(i,n-1,m,n,board);
            }
        }
        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O') {
                recurse(0,j,m,n,board);
            }
            if (board[m-1][j] == 'O') {
                recurse(m-1,j,m,n,board);
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
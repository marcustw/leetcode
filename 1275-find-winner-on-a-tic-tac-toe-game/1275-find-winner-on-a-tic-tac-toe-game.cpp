class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(2, vector<int>(8,0));
        for (int i=0; i<moves.size(); i++) {
            int q = i%2 == 0 ? 0 : 1;
            int r=moves[i][0], c=moves[i][1];
            board[q][r]++;
            board[q][c+3]++;
            if (r == c) board[q][6]++;
            if (r == 2-c) board[q][7]++;
        }
        for (int i=0; i<8; i++) {
            if (board[0][i]==3) return "A";
            if (board[1][i]==3) return "B";
        }
    
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
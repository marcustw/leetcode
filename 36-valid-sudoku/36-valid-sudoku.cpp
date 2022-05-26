class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    int boxNum = (i/3)*3 + j/3;
                    char c = board[i][j];
                    string row = "r" + to_string(i) + c;
                    string col = "c" + to_string(j) + c;
                    string box = "b" + to_string(boxNum) + c;
                    if (s.count(row) || s.count(col) || s.count(box)) return false;
                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                }
            }            
        }
        
        return true;
    }
};

// box numbering
// [
//  [0], [1], [2],
//  [3], [4], [5],
//  [6], [7], [8]
// ]
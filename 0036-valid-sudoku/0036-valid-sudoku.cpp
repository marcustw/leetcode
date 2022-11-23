class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check box
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                unordered_set<char> s;
                for (int p=0; p<3; p++) {
                    for (int q=0; q<3; q++) {
                        char c = board[3*i+p][3*j+q];
                        if (s.find(c) != s.end() && c != '.') {
                            return false;
                        }
                        s.insert(c);
                    }
                }
            }
        }
        
        
        for (int i=0; i<9; i++) {
            unordered_set<char> s1;
            unordered_set<char> s2;
            for (int j=0; j<9; j++) {
                char c1 = board[i][j];
                char c2 = board[j][i];
                if ((s1.find(c1) != s1.end() && c1 != '.') || (s2.find(c2) != s2.end() && c2 != '.')) {
                    return false;
                }
                s1.insert(c1); s2.insert(c2);
            }
        }
        
        return true;
    }
};
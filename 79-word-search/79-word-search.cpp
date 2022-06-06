class Solution {
private:
    int n;
    int m;
    int l;
    
    bool recurse(vector<vector<char>>& board, const char* w, int x, int y) {
        if (*w=='\0') return true;
        if (x<0 || y<0 || x>=n || y>=m || *w!=board[x][y]) {
            return false;
        }
        char c=board[x][y];
        board[x][y]=' ';
        if (recurse(board,w+1,x+1,y)||recurse(board,w+1,x-1,y)||recurse(board,w+1,x,y-1)||recurse(board,w+1,x,y+1)) {
            return true;
        }
        board[x][y]=c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        l=word.length();
        n=board.size();
        m=board[0].size();
        for (int x=0; x<n; x++) {
            for (int y=0; y<m; y++) {
                if (recurse(board,word.c_str(),x,y)) {
                    return true;
                }
            }
        }
        return false;
    }
};
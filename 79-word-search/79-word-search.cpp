class Solution {
private:
    bool recurse(vector<vector<char>>& board, int i, string word, int x, int y) {
        if (i==word.size()) return true;
        if (x<0 || y<0 || x>=board.size() || y>=board[0].size() || word[i]!=board[x][y]) {
            return false;
        }
        char w=board[x][y];
        board[x][y]=' ';
        bool ans=recurse(board,i+1,word,x+1,y)||recurse(board,i+1,word,x-1,y)||recurse(board,i+1,word,x,y-1)||recurse(board,i+1,word,x,y+1);
        board[x][y]=w;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int l=word.length();
        for (int x=0; x<board.size(); x++) {
            for (int y=0; y<board[0].size(); y++) {
                if (word[0]==board[x][y] && recurse(board,0,word,x,y)) {
                    return true;
                }
            }
        }
        return false;
    }
};
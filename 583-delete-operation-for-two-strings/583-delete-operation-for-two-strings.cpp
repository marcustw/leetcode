class Solution {
private:
    vector<vector<int>> dp;
    
    int recurse(string& word1, string& word2, int i, int j) {
        if (i==word1.length() && j==word2.length()) return 0;
        if (dp[i][j]==INT_MAX) {
            if (i==word1.length()) dp[i][j]=word2.length()-j;
            else if (j==word2.length()) dp[i][j]=word1.length()-i;
            else if (word1[i]==word2[j]) dp[i][j]=recurse(word1,word2,i+1,j+1);
            else dp[i][j]=1+min(recurse(word1,word2,i+1,j),recurse(word1,word2,i,j+1));
        }
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        dp.resize(word1.length()+1, vector<int>(word2.length()+1,INT_MAX));
        return recurse(word1, word2,0,0);
    }
};
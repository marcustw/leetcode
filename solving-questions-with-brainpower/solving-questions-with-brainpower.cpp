class Solution {
    long long mostPoints(vector<vector<int>>& qns, vector<long long>& dp, int i) {
        if (i>=qns.size()) return 0L;
        if (dp[i]!=-1L) return dp[i];
        return dp[i]=qns[i][0]+mostPoints(qns, dp, i+1+qns[i][1]);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        long long ans=0L;
        vector<long long> dp(n, -1L);
        dp[n-1]=questions[n-1][0];
        for (int i=n-2; i>=0; i--) {
            dp[i]=max(dp[i+1], mostPoints(questions, dp, i));
        }
        return dp[0];
    }
};
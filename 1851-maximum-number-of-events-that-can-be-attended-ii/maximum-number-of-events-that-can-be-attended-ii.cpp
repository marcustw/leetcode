class Solution {
    vector<vector<int>> dp;

    int recurse(vector<vector<int>>& events, int i, int k) {
        if (i>=events.size() || k==0) return 0;
        if (dp[i][k]!=-1) return dp[i][k];
        int j=i+1;
        while (j<events.size() && events[j][0]<=events[i][1]) ++j;
        return dp[i][k]=max(
            recurse(events, i+1, k),
            events[i][2] + recurse(events, j, k-1)
        );
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        dp=vector<vector<int>>(events.size()+1, vector<int>(k+1, -1));
        return recurse(events, 0, k);
    }
};
class Solution {
    void fill(vector<int>& ans, int i, int dist, bool isLeft) {
        if (isLeft && i>=0 && ans[i]!=0) {
            ans[i]=min(ans[i], dist);
            fill(ans, i-1, dist+1, isLeft);
        }
        if (!isLeft && i<ans.size() && ans[i]!=0) {
            ans[i]=min(ans[i], dist);
            fill(ans, i+1, dist+1, isLeft);
        }
    }
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> ans(n, INT_MAX);
        for (int i=0; i<n; i++)
            if (s[i]==c) ans[i]=0;
        for (int i=0; i<n; i++) {
            if (ans[i]==0) {
                fill(ans, i-1, 1, true);
                fill(ans, i+1, 1, false);
            }
        }
        return ans;
    }
};
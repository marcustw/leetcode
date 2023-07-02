class Solution {
    int ans=0;

    void backtrack(int start, vector<vector<int>>& req, vector<int>& g, int n, int count) {
        if (start==req.size()) {
            for (int i=0; i<n; ++i)
                if (g[i]!=0) return;
            ans=max(count, ans);
            return;
        }
        g[req[start][0]]--;
        g[req[start][1]]++;
        backtrack(start+1, req, g, n, count+1);

        g[req[start][0]]++;
        g[req[start][1]]--;
        backtrack(start+1, req, g, n, count);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> g(n, 0);
        backtrack(0, requests, g, n, 0);
        return ans;
    }
};
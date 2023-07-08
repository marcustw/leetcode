class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if (k==1 || n==k) return 0LL;
        vector<int> ws;
        for (int i=0; i<n-1; ++i) {
            ws.push_back(weights[i]+weights[i+1]);
        }
        sort(ws.begin(), ws.end());
        long long mins=0LL, maxs=0LL;
        for (int i=0; i<k-1; ++i) {
            mins += ws[i];
            maxs += ws[n-2-i];
        }
        return maxs-mins;
    }
};
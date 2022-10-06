class Solution {
    struct Comp {
        bool operator() (vector<int>& a, vector<int>& b) {
            if (a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        }
    };
    
public:
    // Longest increasing subsequence
    int maxEnvelopes(vector<vector<int>>& es) {
        sort(es.begin(), es.end(), Comp());
        vector<int> ls;
        for (int i=0; i<es.size(); i++) {
            auto it = lower_bound(ls.begin(), ls.end(), es[i][1]);
            if (it==ls.end()) ls.push_back(es[i][1]);
            else (*it) = es[i][1];
        }
        return ls.size();
    }
};
class Solution {
    vector<int> v;

    int find(int x) {
        if (v[x]!=x) {
            v[x] = find(v[x]);
        }
        return v[x];
    }

    void join(int x, int y) {
        int fx=find(x), fy=find(y);
        if (fx!=fy) {
            v[fy]=fx;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int n=isConnected.size();
        v=vector<int>(n);
        iota(v.begin(), v.end(), 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j && isConnected[i][j]) {
                    join(i, j);
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (find(i) != v[i]) v[i]=find(i);
        }
        return unordered_set<int>(v.begin(), v.end()).size();
    }
};
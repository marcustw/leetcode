struct DisjointSet {
    vector<int> v;
    DisjointSet(int n) {
        this->v = vector<int>(n);
        iota(v.begin(), v.end(), 0);
    }

    int find(int x) {
        if (v[x] != x) {
            v[x] = find(v[x]);
        }
        return v[x];
    }

    void join(int x, int y) {
        int dx=find(x), dy=find(y);
        if (dx != dy) {
            v[dx] = dy;
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        DisjointSet ds = DisjointSet(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<graph[i].size(); j++) {
                if (ds.find(i) == ds.find(graph[i][j]))
                    return false;
                ds.join(graph[i][0], graph[i][j]);
            }
        }
        return true;
    }
};
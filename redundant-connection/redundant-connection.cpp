class DisjointSet {
    vector<int> v;
public:
    DisjointSet(int n) {
        v.resize(n);
        iota(v.begin(), v.end(), 1);
    }

    int find(int x) {
        if (v[x-1] != x) {
            v[x-1] = find(v[x-1]);
        }
        return v[x-1];
    }

    bool join(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            v[fx-1] = fy;
            return true;
        }
        return false;
    }    

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds = DisjointSet(edges.size());
        for (auto& edge : edges) {
            if (!ds.join(edge[0], edge[1])) return edge;
        }
        return edges.back();
    }
};
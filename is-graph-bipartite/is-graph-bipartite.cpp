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

    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        if (colors[node] != 0) return colors[node] == color;
        
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (!dfs(graph, colors, neighbor, -color)) return false;
        }
        return true;
    }
    // Dfs answer -> colouring graph: no node should be coloured by 2 colours
    bool isBipartiteDfs(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n, 0);
        for (int i=0; i<n; i++) {
            if (colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
        }
        return true;
    }

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
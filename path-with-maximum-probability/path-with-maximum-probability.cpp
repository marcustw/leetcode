typedef pair<double, int> P;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<P>> g(n);
        for (int i=0; i<edges.size(); ++i) {
            vector<int> e=edges[i];
            g[e[0]].push_back({succProb[i], e[1]});
            g[e[1]].push_back({succProb[i], e[0]});
        }
        priority_queue<P> pq;
        pq.push({1.0, start});
        vector<bool> visited(n, false);
        while (!pq.empty()) {
            P p=pq.top();
            pq.pop();
            if (p.second==end) return p.first;
            visited[p.second]=true;
            for (auto& e : g[p.second]) {
                if (!visited[e.second])
                    pq.push({p.first*e.first, e.second});
            }
        }
        return 0.0;
    }
};
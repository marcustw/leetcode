class Solution {
public:
    typedef pair<int,int> p;
    // Dijkstra Algorithmn
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n==1 && k==1) return 0;
        vector<vector<p>> adj_list(n+1);
        for (auto time : times)
            adj_list[time[0]].push_back({time[1],time[2]});
        vector<int> dist(n+1,INT_MAX);
        vector<bool> vis(n+1,false);
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,k});
        dist[k]=0;
        while (!pq.empty()) {
            int u=pq.top().second;
            pq.pop();
            if (!vis[u]) {
                vis[u]=true;
                for (auto nbr : adj_list[u]) {
                    int v=nbr.first, w=nbr.second;
                    if (dist[v]>dist[u]+w) {
                        dist[v]=dist[u]+w;
                        pq.push({dist[v],v});
                    }
                }
            }
            
        }
        int ans= *max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX ? -1 : ans;
    }
};
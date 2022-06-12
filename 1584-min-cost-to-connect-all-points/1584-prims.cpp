class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //mst
        int n=points.size();
        int ans=0, i=0, v=0;
        priority_queue<pair<int,int>> pq;
        vector<bool> visited(n);
        while(++v<n) {
            visited[i]=true;
            for (int j=0; j<n; j++) {
                if (!visited[j]) {
                    int manhattan_dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                    pq.push({-manhattan_dist,j}); //negate dist so smallest dist pops first
                }
            }
            while (visited[pq.top().second]) pq.pop();
            ans+=(-pq.top().first);
            i=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};

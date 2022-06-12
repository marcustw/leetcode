class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0, i = 0, connected = 0;
        vector<int> min_d(n, 10000000);
        while (++connected < n) {
            min_d[i] = INT_MAX;
            int min_j = i;
            for (int j = 0; j < n; ++j)
                if (min_d[j] != INT_MAX) {
                    min_d[j] = min(min_d[j], abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                    min_j = min_d[j] < min_d[min_j] ? j : min_j;
                }
            ans += min_d[min_j];
            i = min_j;
        }
        return ans;
    }
};

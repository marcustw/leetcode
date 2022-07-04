typedef pair<int,vector<int>> pi;

class Solution {

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<vector<int>> ans;
        for (auto point : points) {
            int dist = pow(point[0],2) + pow(point[1],2);
            pq.push({dist,point});
        }
        while (k-->0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
class Solution {
    class Comparator {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0]+a[1])>(b[0]+b[1]);
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        for (int i=0; i<n && i<k; ++i) pq.push({nums1[i], nums2[0], 0});
        while (k-- && !pq.empty()) {
            auto p=pq.top(); pq.pop();
            ans.push_back({p[0], p[1]});
            if (p[2]==m-1) continue;
            pq.push({p[0], nums2[p[2]+1], p[2]+1});
        }
        return ans;
    }
};
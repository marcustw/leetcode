class Solution {
    class Comparator {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0]+a[1])>(b[0]+b[1]);
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int sum=nums1[i]+nums2[j];
                if (pq.size()<k) pq.push({sum, nums1[i], nums2[j]});
                else if (sum<pq.top()[0]) {
                    pq.pop();
                    pq.push({sum, nums1[i], nums2[j]});
                } else break;
            }
        }
        while (!pq.empty()) {
            auto p=pq.top(); pq.pop();
            ans.push_back({p[1], p[2]});
        }
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};
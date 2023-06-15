typedef pair<int, int> P;
class Solution {
    long long ans=0L;
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n=costs.size(), lo, hi;
        for (lo=0; lo<candidates && lo<n; ++lo) {
            pq.push({costs[lo], lo});
        }
        for (hi=n-1; hi>=n-candidates && hi>=0; hi--) {
            pq.push({costs[hi], hi});
        }
        unordered_set<int> idx;
        while (idx.size()<k) {
            P p=pq.top(); pq.pop();
            if (idx.find(p.second) != idx.end()) continue;
            ans+=p.first;
            idx.insert(p.second);
            if (p.second<lo && lo<=hi) {
                pq.push({costs[lo], lo++});
            } else if (p.second>hi && lo<=hi) {
                pq.push({costs[hi], hi--});
            }
        }
        return ans;
    }
};
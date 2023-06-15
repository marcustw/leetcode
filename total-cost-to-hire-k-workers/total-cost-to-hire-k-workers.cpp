typedef pair<int, int> P;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n=costs.size(), lo=0, hi=n-1;
        long long ans=0L;
        while (k>0) {
            while (pq1.size()<candidates && lo<=hi) pq1.push(costs[lo++]);
            while (pq2.size()<candidates && lo<=hi) pq2.push(costs[hi--]);
            if (!pq1.empty() && (pq2.empty() || pq1.top() <= pq2.top())) {
                ans+=pq1.top();
                cout << "add pq1: " << pq1.top() << endl;
                pq1.pop();
            } else {
                ans+=pq2.top();
                cout << "add pq2: " << pq2.top() << endl;
                pq2.pop();
            }
            k--;
        }
        return ans;
    }
};
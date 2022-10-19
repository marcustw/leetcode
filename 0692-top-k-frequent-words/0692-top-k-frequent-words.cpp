class Solution {
    typedef pair<int, string> p;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (string& w : words) {
            counts[w]++;
        }
        vector<string> ans;
        auto cmp = [](p p1, p p2) {
            return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
        };
        priority_queue<p, vector<p>, decltype(cmp)> pq(cmp);
        for (auto& m : counts) {
            pq.push({ m.second, m.first });
        }
        
        while (pq.size() >= k && k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};
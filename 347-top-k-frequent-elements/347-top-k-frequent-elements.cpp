class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for (int i=0; i<nums.size(); i++) {
            int key = nums[i];
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key]++;
            }
        }
        priority_queue<pair<int,int>> pq;
        for (auto& it : umap) {
            pq.push(make_pair(it.second, it.first));
        }
        vector<int> result;
        for (int i=0; i<k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int, int> m;
        for (const int& i : nums) m[i]++;
        for (auto& p : m) {
            if (k==0) {
                if (p.second>1) ans++;
            } else if (m.find(p.first+k) != m.end()) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for (const int& a : arr) {
            m[a]++;
        }
        unordered_set<int> s;
        for (const auto& p : m) {
            if (s.find(p.second) != s.end()) return false;
            s.insert(p.second);
        }
        return true;
    }
};
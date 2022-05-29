class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.count(n) == 0) s.insert(n);
            else s.erase(n);
        }
        return *s.begin();
    }
};
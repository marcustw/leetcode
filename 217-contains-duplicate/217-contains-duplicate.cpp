class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (auto n:nums) {
            if (s.count(n)>0) return true;
            s.insert(n);
        }
        return false;
    }
};
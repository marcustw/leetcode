class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | 1 << i;
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(mask & num);
            }
            int temp = res | 1 << i;
            for (int num : s) {
                if (s.count(num ^ temp) != 0) {
                    res = temp;
                }
            }
        }
        return res;
    }
};
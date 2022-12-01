class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        for (const int& num : nums) {
            m[gcd(num, k)]++;
        }
        for (const auto& p1 : m) {
            for (const auto& p2 : m) {
                if (p1.first <= p2.first && ((long) p1.first * p2.first) % k == 0) {
                    ans += p1.first == p2.first
                        ? (long) p1.second * (p2.second - 1) / 2
                        : (long) p1.second * p2.second; 
                }
            }
        }
        return ans;
    }
};
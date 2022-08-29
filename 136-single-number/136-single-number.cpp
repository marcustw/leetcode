class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum ^= n;
        return sum;
    }
};
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sumEven = 0;
        for (int& n : nums) {
            if (n%2 == 0) sumEven += n;
        }
        for (auto& q : queries) {
            int index = q[1];
            int add = q[0];
            int cur = nums[index];
            if (cur%2==0) {
                nums[index] += add;
                if (nums[index]%2 != 0) sumEven -= cur;
                else sumEven+=add;
            } else {
                nums[index] += add;
                if (nums[index]%2 == 0) sumEven += nums[index];
            }
            ans.push_back(sumEven);
        }
        return ans;
    }
};
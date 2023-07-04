class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int i=0; i<32; ++i) {
            int sum=0;
            int mask=1<<i;
            for (const int& n : nums) {
                if (n&mask)
                    ++sum;
            }
            if (sum%3==1)
                ans|=mask;
        }
        return ans;
    }
};
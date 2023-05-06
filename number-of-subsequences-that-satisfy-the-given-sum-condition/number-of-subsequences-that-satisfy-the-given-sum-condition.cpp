class Solution {
    int MOD=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans=0L;
        int n=nums.size(), lo=0, hi=n-1;

        vector<int> pows(n, 1);
        for (int i=1; i<n; i++) {
            pows[i] = (2*pows[i-1]) % MOD;
        }

        while (lo<=hi) {
            if (nums[lo] + nums[hi] > target) hi--;
            else ans += pows[hi-lo++];
            ans %= MOD;
        }
        return (int) ans;
    }
};
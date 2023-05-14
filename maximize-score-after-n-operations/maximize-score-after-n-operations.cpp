class Solution {
    int dp[8][16384] = {};
    
    int solve(vector<int>& nums, vector<vector<int>>& g, int i=1, int mask=0) {
        int l=nums.size(), n=l/2;
        if (i>n) return 0;
        if (!dp[i][mask]) {
            for (int j=0; j<l; j++) {
                for (auto k=j+1; k<l; k++) {
                    int mask2=(1<<j)+(1<<k);
                    if ((mask & mask2) == 0) {
                        dp[i][mask] = max(dp[i][mask], i*g[j][k] + solve(nums, g, i+1, (mask+mask2)));
                    }
                }
            }
        }
        return dp[i][mask];
    }
public:
    int maxScore(vector<int>& nums) {
        int l=nums.size();
        vector<vector<int>> g(l, vector<int>(l, 0));
        for (int i=0; i<l; i++) {
            for (int j=i+1; j<l; j++) {
                g[i][j]=gcd(nums[i], nums[j]);
            }
        }
        return solve(nums, g);
    }
};
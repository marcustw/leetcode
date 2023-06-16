class Solution {
    long long MOD=1e9+7;
    vector<vector<long long>> table;

    long long dfs(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return 1;
        vector<int> leftTree, rightTree;
        for (int i=1; i<n; ++i) {
            if (nums[i]<nums[0]) leftTree.push_back(nums[i]);
            else rightTree.push_back(nums[i]);
        }
        long long left = dfs(leftTree) % MOD;
        long long right = dfs(rightTree) % MOD;
        int l=leftTree.size(), r=rightTree.size();
        return (((table[n-1][l] * left) % MOD) * right) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        table.resize(n+1);
        for (int i=0; i<n+1; ++i) {
            table[i] = vector<long long>(i+1, 1L);
            for (int j=1; j<i; ++j)
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MOD;
        }
        long long ans=dfs(nums) % MOD;
        return ans-1;
    }
};
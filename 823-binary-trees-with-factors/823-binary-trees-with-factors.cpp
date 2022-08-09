class Solution {
    int MOD=1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        long ans=0;
        unordered_map<int,long> m;
        for (int i=0; i<n; i++) {
            int a = arr[i];
            m[a] = 1;
            for (int j=0; j<i; j++) {
                int b=arr[j];
                if (a % b == 0) {
                    int c = a/b;
                    m[a] += m[b] * m[c];
                    m[a] %= MOD;
                }
            }
            ans += m[a];
            ans %= MOD;
        }
        return ans;
    }
};
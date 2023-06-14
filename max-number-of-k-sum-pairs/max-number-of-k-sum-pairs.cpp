class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int& n : nums) m[n]++;
        int ans=0;
        for (const int& n : nums) {
            if (k-n==n) {
                if (m[n]>=2) {
                    m[n]-=2;
                    ans++;
                }
            } else if (m[k-n]>0 && m[n]>0) {
                m[k-n]--;
                m[n]--;
                ans++;
            }
        }
        return ans;
    }
};
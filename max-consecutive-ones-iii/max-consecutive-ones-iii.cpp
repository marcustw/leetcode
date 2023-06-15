class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo=0, hi=0, flips=0, ans=0, count=0;
        while (hi<nums.size()) {
            if (flips>k) {
                flips-=(nums[lo]==0);
                lo++;
                count--;
                continue;
            }
            if (nums[hi++]==0) flips++;
            count++;
            if (flips<=k)
                ans=max(count,ans);
                // cout << lo << ", " << hi << " : " << count << endl;
        }
        return ans;
    }
};
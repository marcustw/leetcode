class Solution {
    string getString(int lo, int hi) {
        if (lo==hi) return to_string(lo);
        return to_string(lo) + "->" + to_string(hi);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if (n==0) return ans;
        int lo=nums[0], hi=nums[0];

        for (int i=1; i<n; i++) {
            if (nums[i]==hi+1) hi++;
            else {
                ans.push_back(getString(lo, hi));
                lo=hi=nums[i];
            }
        }

        ans.push_back(getString(lo, hi));
        return ans;
    }
};
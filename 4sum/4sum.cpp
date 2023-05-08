class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for (int i=0; i<n-3; i++) {
            if (i!=0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<n-2; j++) {
                if (j!=i+1 && nums[j]==nums[j-1]) continue;
                int ni=nums[i], nj=nums[j], lo=j+1, hi=n-1;
                long t1=ni+nj;
                while (lo<hi) {
                    long t2=nums[lo]+nums[hi];
                    if (target==t1+t2) {
                        ans.push_back({ni, nj, nums[lo], nums[hi]});
                        lo++;
                        hi--;
                        while (lo<hi && nums[lo]==nums[lo-1]) lo++;
                        while (lo<hi && nums[hi]==nums[hi+1]) hi--;
                    } else if (t2+t1 < target) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};
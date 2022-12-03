class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0;
        unordered_map<int, int> m;
        int ans=0, sum=0;
        while (r<n) {
            if (!m[nums[r]]) {
                sum+=nums[r];
                m[nums[r]]=1;
                r++;
            } else {
                ans=max(ans,sum);
                m[nums[l]]=0;
                sum-=nums[l];
                l++;
            }
        }
        ans=max(ans,sum);
        return ans;
    }
};